project_dir := .

include make/common.in

# find all directories with Makiefile inside
make_dirs := $(foreach realdir, $(foreach pseudodir, $(wildcard *), $(wildcard $(pseudodir)/Makefile)), $(dir $(realdir)))
local_domains := $(sort $(patsubst %/,%,$(make_dirs)))
app_name = Moj_serwer

# find all src
get_sources = $(patsubst $(project_dir)/$1/src/%.cpp,$(bin_dir)/$1/objects/src/%.o,$(call recursive_wildcard,$(project_dir)/$1/src,*.cpp))
build_objects = $(foreach domain_to_search,$(local_domains),$(call get_sources,$(domain_to_search)))

#includes_interfaces = $(foreach domain,$(local_domains),$(interface_dir)/$(domain))
includes += $(patsubst %,-I%,$(includes_interfaces))
#includes += $(patsubst %,-I%,$(call recursive_directories,$(domain_src),*))

phony += build run install kill clean

# targets
.PHONY: $(phony)

build_tests: $(make_dirs)
	@$(foreach domain,$(local_domains),$(MAKE) -C $(domain) build_tests;)

run_tests: kill
	@$(foreach domain,$(local_domains),$(MAKE) -C $(domain) run_tests;)

__build_main__:
	@$(cxx) $(cxx_flags) -fPIC $(includes) -c main.cpp -o $(objects_dir)/main.o

build: __prepare__ __build_main__ __build_domains__

	@echo "\033[0;32m[ BUILD    ]\033[0;39m" $(app_name)
	@$(cxx) $(cxx_flags) $(build_objects) $(includes) $(objects_dir)/main.o $(boost_libs) -o $(build_dir)/$(app_name) 

run:
	@echo "\033[0;32m[ RUN      ]\033[0;39m" $(app_name)
#	@$(if $(shell pidof $(app_name)),@echo "\033[0;32m[ RUN      ]\033[0;39m" Already running,@$(build_dir)/$(app_name) $(foreach param, $(parameters), $(param)=$($(param))))
	@$(build_dir)/$(app_name) $(foreach param, $(parameters), $(param)=$($(param)))
	
kill:
	@echo "\033[0;31m[ KILL     ]\033[0;39m" $(app_name)
#	@$(if $(shell pidof $(app_name)),$(call kill,$(app_name)) @echo "\033[0;31m[       OK ]\033[0;39m" Killed successfully,@echo "\033[0;31m[       OK ]\033[0;39m" Nothing to kill)
	$(call kill,$(app_name))
	
__build_domains__:
	@$(foreach domain,$(local_domains),$(MAKE) -C $(domain) build;)

clean:
	@$(foreach domain,$(local_domains),$(MAKE) -C $(domain) clean;)
	@echo "\033[0;33m[ CLEAN    ]\033[0;39m" $(app_name)
	@$(rmdir) $(build_dir)/$(app_name)
	@$(rmdir) $(objects_dir)/$(app_name).o
	@$(rmdir) $(build_dir)
	@$(rmdir) $(objects_dir)
	@$(rmdir) $(bin_dir)
	@$(rmdir) /tmp/ftp_server
	@$(rmdir) /tmp/server_root

clean_logs:
	@$(rmdir) ~/Desktop/inzynierka/logs
