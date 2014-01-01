#   shell
#   Copyright 2014 Michael Gruber
#
#   Licensed under the Apache License, Version 2.0 (the "License");
#   you may not use this file except in compliance with the License.
#   You may obtain a copy of the License at
#
#       http://www.apache.org/licenses/LICENSE-2.0
#
#   Unless required by applicable law or agreed to in writing, software
#   distributed under the License is distributed on an "AS IS" BASIS,
#   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#   See the License for the specific language governing permissions and
#   limitations under the License.

compile:
#   See http://stackoverflow.com/questions/3355298/unistd-h-and-c99-on-linux
#   to understand why _XOPEN_SOURCE is set to 500

	gcc -std=c99 -Wall shell.c -o shell -lreadline -D_XOPEN_SOURCE=500
