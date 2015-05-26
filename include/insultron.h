/*
  Copyright (C) 2015 Mathieu Bernard <mathieu_bernard@laposte.net>

  This file is part of Insultron

  Insultron is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this Insultron. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef INSULTRON_H
#define INSULTRON_H

#include <chrono>
#include <random>
#include <string>
#include <vector>
#include <iostream>

//! Générateur d'insulte aléatoire
class insultron
{
public:
  //! Constructeur par défaut
  insultron();

  //! Destructeur
  virtual ~insultron();

  //! Renvoie une insulte générée aléatoirement
  std::string insulte() const;

  //! Dirige une insulte vers un flux de sortie
  friend std::ostream& operator<<( std::ostream& out_stream, const insultron& my_insultron );

protected:
  //! La table décompose une insulte en plusieurs segments, chacun
  //! composé de plusieurs alternatives.
  typedef std::vector<std::vector<std::string> > table_type;

  //! Renvoie une table d'insulte par défaut
  static table_type default_table();

  //! La table d'insulte
  const table_type m_table;
};

#endif // INSULTRON_H
