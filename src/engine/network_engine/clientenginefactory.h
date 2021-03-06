/*****************************************************************************
 * PokerTH - The open source texas holdem engine                             *
 * Copyright (C) 2006-2012 Felix Hammer, Florian Thauer, Lothar May          *
 *                                                                           *
 * This program is free software: you can redistribute it and/or modify      *
 * it under the terms of the GNU Affero General Public License as            *
 * published by the Free Software Foundation, either version 3 of the        *
 * License, or (at your option) any later version.                           *
 *                                                                           *
 * This program is distributed in the hope that it will be useful,           *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of            *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
 * GNU Affero General Public License for more details.                       *
 *                                                                           *
 * You should have received a copy of the GNU Affero General Public License  *
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.     *
 *                                                                           *
 *                                                                           *
 * Additional permission under GNU AGPL version 3 section 7                  *
 *                                                                           *
 * If you modify this program, or any covered work, by linking or            *
 * combining it with the OpenSSL project's OpenSSL library (or a             *
 * modified version of that library), containing parts covered by the        *
 * terms of the OpenSSL or SSLeay licenses, the authors of PokerTH           *
 * (Felix Hammer, Florian Thauer, Lothar May) grant you additional           *
 * permission to convey the resulting work.                                  *
 * Corresponding Source for a non-source form of such a combination          *
 * shall include the source code for the parts of OpenSSL used as well       *
 * as that of the covered work.                                              *
 *****************************************************************************/

#ifndef CLIENTENGINEFACTORY_H
#define CLIENTENGINEFACTORY_H

#include <enginefactory.h>

#include <handinterface.h>
#include <boardinterface.h>
#include <playerinterface.h>
#include <log.h>

#include <boost/shared_ptr.hpp>
#include <vector>


class ConfigFile;

class ClientEngineFactory : public EngineFactory
{
public:
	ClientEngineFactory();
	~ClientEngineFactory();

	virtual boost::shared_ptr<HandInterface> createHand(boost::shared_ptr<EngineFactory> f, GuiInterface *g, boost::shared_ptr<BoardInterface> b, Log *l, PlayerList sl, PlayerList apl, PlayerList rpl, int id, int sP, int dP, int sB,int sC);
	virtual boost::shared_ptr<BoardInterface> createBoard(unsigned dp);
	virtual boost::shared_ptr<PlayerInterface> createPlayer(int id, unsigned uniqueId, PlayerType type, std::string name, std::string avatar, int sC, bool aS, bool sotS, int mB);
	virtual std::vector<boost::shared_ptr<BeRoInterface> > createBeRo(HandInterface *hi, unsigned dP, int sB);
};

#endif
