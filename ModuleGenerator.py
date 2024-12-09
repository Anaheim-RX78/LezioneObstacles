import os
import sys

def create_unreal_module(module_name):
    # Get the current directory (assumed to be the project root)
    project_dir = os.getcwd()
    source_dir = os.path.join(project_dir, "Source")
    module_dir = os.path.join(source_dir, module_name)
    build_file = os.path.join(module_dir, f"{module_name}.Build.cs")
    module_header = os.path.join(module_dir, f"{module_name}.h")
    module_cpp = os.path.join(module_dir, f"{module_name}.cpp")

    # Check if the source directory exists
    if not os.path.isdir(source_dir):
        print("Error: Source directory not found. Ensure this script is placed in the root of an Unreal project.")
        sys.exit(1)

    # Create the module directory
    os.makedirs(module_dir, exist_ok=True)

    # Generate the module's .Build.cs file
    with open(build_file, "w") as bf:
        bf.write(f"""\
using UnrealBuildTool;

public class {module_name} : ModuleRules
{{
    public {module_name}(ReadOnlyTargetRules Target) : base(Target)
    {{
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PublicDependencyModuleNames.AddRange(new string[] {{ "Core", "CoreUObject", "Engine", "InputCore" }});
        PrivateDependencyModuleNames.AddRange(new string[] {{ }});
    }}
}}
""")

    # Generate the module's header file
    with open(module_header, "w") as mh:
        mh.write(f"""\
#pragma once

#include "CoreMinimal.h"
""")

    # Generate the module's source file
    with open(module_cpp, "w") as mc:
        mc.write(f"""\
#include "{module_name}.h"

DEFINE_LOG_CATEGORY_STATIC(Log{module_name}, Log, All);

class F{module_name}Module : public IModuleInterface
{{
public:
    virtual void StartupModule() override
    {{
        UE_LOG(Log{module_name}, Warning, TEXT("{module_name} module has started!"));
    }}

    virtual void ShutdownModule() override
    {{
        UE_LOG(Log{module_name}, Warning, TEXT("{module_name} module has shut down."));
    }}
}};

IMPLEMENT_MODULE(F{module_name}Module, {module_name})
""")

    print(f"Module {module_name} created successfully in {module_dir}.")
    print("Don't forget to regenerate project files and recompile!")

def main():
    if len(sys.argv) < 2:
        print("Usage: python create_unreal_module.py <ModuleName>")
        sys.exit(1)

    module_name = sys.argv[1]
    create_unreal_module(module_name)

if __name__ == "__main__":
    main()
