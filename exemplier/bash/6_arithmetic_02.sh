#!/bin/sh

#
# ENSICAEN
# 6 Boulevard Maréchal Juin
# F-14050 Caen Cedex
#
# Unix System Programming Examples / Exemplier de programmation système Unix
# "Shell bash" / "Interpréteur de commandes bash"
#
# Copyright (C) 1995-2016 Alain Lebret (alain.lebret@ensicaen.fr)
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#    http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

# Another simple script to show some arithmetic operations

echo -n "Enter the first number: "; read x
echo -n "Enter the second number: "; read y

sum=$(($x + $y))
difference=$(($x - $y))
product=$(($x * $y))
ratio=$(($x / $y))
rest=$(($x % $y))

# Displaying results
echo "Sum: $sum"
echo "Difference: $difference"
echo "Product: $product"
echo "Ratio: $ratio"
echo "Rest: $rest"
