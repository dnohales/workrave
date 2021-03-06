// TimePredFactory.cc
//
// Copyright (C) 2001, 2002, 2007 Rob Caelers <robc@krandor.nl>
// All rights reserved.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "TimePredFactory.hh"
#include "DayTimePred.hh"
#if 0
#include "WeekTimePred.hh"
#endif

using namespace std;

TimePred *
TimePredFactory::create_time_pred(string spec)
{
  TimePred *pred = 0;
  bool ok = false;

  std::string type;
  std::string::size_type pos = spec.find('/');

  if (pos != std::string::npos)
    {
      type = spec.substr(0, pos);
      spec = spec.substr(pos + 1);

      if (type == "day")
        {
          DayTimePred *dayPred = new DayTimePred();
          ok = dayPred->init(spec);
          pred = dayPred;
        }
#if 0
      else if (type == "week")
        {
          WeekTimePred *weekPred = new WeekTimePred();
          ok = weekPred->init(spec);
          pred = weekPred;
        }
#endif
    }

  if (pred && !ok)
    {
      delete pred;
      pred = NULL;
    }

  return pred;
}
