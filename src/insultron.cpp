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

#include <insultron.h>

insultron::insultron() : m_table(default_table()) {}

insultron::~insultron(){}

std::string insultron::insulte() const
{
  std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
  std::string insulte;
  for(const auto& t : m_table )
    {
      std::uniform_int_distribution<std::size_t> distribution(0, t.size() - 1);
      insulte += t[distribution(generator)] + " ";
    }
  return insulte.substr(0, insulte.size()-1) + ".";
}

std::ostream& operator<<(std::ostream& out_stream, const insultron& my_insultron)
{
  return out_stream << my_insultron.insulte();
}

insultron::table_type insultron::default_table()
{
  table_type table;

  table.push_back({"Sorte de",
        "Tête de",
        "Variété de",
        "Espèce de",
        "Sosie de",
        "Face de",
        "Figure de",
        "Raclure de",
        "Crême de"});

  table.push_back({"termite",
        "morpion",
        "couille de veau",
        "cochon sauvage",
        "puce",
        "souris",
        "neuneu",
        "sodomite",
        "parasite",
        "cafard",
        "bidet",
        "crétin des Alpes",
        "trou de balle",
        "primate",
        "balance",
        "fiente moisie",
        "déchet nucléaire",
        "pithécanthrope"});

  table.push_back({"crasseux",
        "analphabète",
        "malotru",
        "craignos",
        "obsolète",
        "désuet",
        "dégénéré",
        "qui sent la fiote",
        "boutonneux",
        "purulant",
        "transatlantique",
        "qui sert à rien",
        "qui sent des pieds",
        "des bois",
        "végétatif",
        "trisomique",
        "lobotomisé"});

  table.push_back({"tu ressembles à",
        "t'es comme",
        "tu me fais penser à",
        "tu es",
        "on pourrait te comparer à",
        "tu me fais penser à",
        "tu vaux pas mieux que"});

  table.push_back({"un petit nain",
        "un petit bouffon",
        "un panaris",
        "un furoncle",
        "un gland",
        "un scarabée",
        "un cancrelat",
        "une chaussure trouée",
        "un nain de jardin",
        "un bug dans Windows",
        "un myopathe décérébré"});

  table.push_back({"de service,",
        "qui est heureux comme un pneu,",
        "qui manque de personnalité,",
        "en polystyrène,",
        "tuberculeux",
        "détérioré,",
        "qui pue des pieds,",
        "qui sait pas faire une addition,",
        "baveux,",
        "qui coule de partout,",
        "vert de trouille,",
        "jaune devant marron derrière,"});

  table.push_back({"je rêve de",
        "je voudrais seulement",
        "je crêve d'envie de",
        "je fantasme à l'idée de",
        "j'ai fait le pari de",
        "je ris en pensant à",
        "je me marre grave à l'idée de",
        "je sais pas ce qui me retient de",
        "je vomis à l'idée de",
        "je vais malgré tout le respect que je te dois",
        "moi, mes 3 frères et mes 12 cousins on va"});

  table.push_back({"te mettre un scorpion dans le pantalon",
        "te mettre un string léopard",
        "te faire lire l'encyclopédie universalis en entier",
        "te faire un piercing entre les narines",
        "te pousser dans un océan d'orties",
        "te souder la raie du cul",
        "te mettre ta gueule dans ton cul",
        "te souiller comme jamais",
        "te chanter la digue du cul",
        "te chier dessus",
        "te prendre comme une vieille canaille",
        "t'enfiler par derrière",
        "t'arranger ta sale gueule",
        "te faire bouffer ton slip",
        "te faire des bisous",
        "te ramoner l'urètre avec du gros sable",
        "te pisser à la raie"});

  table.push_back({"jusqu'à l'aube",
        "devant témoin",
        "sous la lune",
        "devant huissier",
        "vite fait bien fait",
        "sur la place de la concorde",
        "dans ma benz benz benz",
        "pendant la récrée",
        "devant la machine à café",
        "entre les cuisses de ta maman",
        "derrière l'abri bus",
        "pour rigoler",
        "pour le fun",
        "dans la grange du vieux René",
        "avec tous mes outils",
        "devant toute ta famille",
        "dans un club échangiste"});

  return table;
}
