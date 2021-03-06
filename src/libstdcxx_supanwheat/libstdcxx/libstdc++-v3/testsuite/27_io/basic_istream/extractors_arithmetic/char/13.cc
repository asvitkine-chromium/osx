// 1999-04-12 bkoz

// Copyright (C) 1999, 2000, 2002, 2003 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 2, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING.  If not, write to the Free
// Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307,
// USA.

// 27.6.1.2.2 arithmetic extractors

#include <istream>
#include <sstream>
#include <locale>
#include <testsuite_hooks.h>

// libstdc++/3720 part two
void test13()
{
  using namespace std;
  bool test __attribute__((unused)) = true;
  const char* l2 = "1.2345678901234567890123456789012345678901234567890123456"
                   "  "
                   "1246.9";

  // 1 
  // used to core.
  double d;
  istringstream iss1(l2);
  iss1 >> d;
  iss1 >> d;
  VERIFY (d > 1246 && d < 1247);

  // 2
  // quick test for failbit on maximum length extraction.
  int i;
  int max_digits = numeric_limits<int>::digits10 + 1;
  string digits;
  for (int j = 0; j < max_digits; ++j)
    digits += '1';
  istringstream iss2(digits);
  iss2 >> i;
  VERIFY( !iss2.fail() );

  digits += '1';
  i = 0;
  iss2.str(digits);
  iss2.clear();
  iss2 >> i; 
  VERIFY( i == 0 );
  VERIFY( iss2.fail() );
}

int main()
{
  test13();
  return 0;
}
