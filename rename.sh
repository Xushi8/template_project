project_name='hello_newproject'
namespace_name='new_project'
macro_and_cmake_name='HELLO_PROJECT'

# 当前脚本的名称
current_script=$(basename "$0")

find . -type f ! -name "$current_script" -not -path "./.git/*" -print0 | xargs -0 sed -i "s/template_project/$project_name/g"
find . -type f ! -name "$current_script" -not -path "./.git/*" -print0 | xargs -0 sed -i "s/basic_namespace/$namespace_name/g"
find . -type f ! -name "$current_script" -not -path "./.git/*" -print0 | xargs -0 sed -i "s/BASIC_PROJECT/$macro_and_cmake_name/g"
find . -type d ! -name "$current_script" -not -path "./.git/*" -name "template_project" -print0 | xargs -0 -I {} sh -c 'mv "$1" "$(dirname "$1")/'"$project_name"'"' _ {}
