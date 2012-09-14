root_include_dir   := include
root_source_dir    := src
source_subdirs     := . agents links util util/geometry body environment
compile_flags      := -Wall -MD 
#link_flags         := -s 
libraries          := -ldl

relative_include_dirs   	:= $(addprefix ../../, $(root_include_dir))
relative_source_dirs   		:= $(addprefix ../../$(root_source_dir)/, $(source_subdirs))
objects_dirs               := $(addprefix $(root_source_dir)/, $(source_subdirs))
objects                    := $(patsubst ../../%, %, $(wildcard $(addsuffix /*.c*, $(relative_source_dirs))))
objects                    := $(objects:.cpp=.o)
objects                    := $(objects:.c=.o)

all : $(program_name)
print : objects_dirs
$(program_name) : obj_dirs $(objects)
	g++ -o $@ $(objects) $(link_flags) $(libraries)
 
obj_dirs :
	mkdir -p $(objects_dirs)
 
VPATH := ../../
 
%.o : %.cpp
	g++ -o $@ -c $< $(compile_flags) $(build_flags) $(addprefix -I, $(relative_include_dirs))
 
%.o : %.c
	g++ -o $@ -c $< $(compile_flags) $(build_flags) $(addprefix -I, $(relative_include_dirs))
 
#.PHONY : clean
 
#clean :
#	rm -rf bin obj
 
include $(wildcard $(addsuffix /*.d, $(objects_dirs)))
