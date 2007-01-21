/***************************************************************************
 *   Copyright (C) 2006 by Felix Hammer   *
 *   f.hammer@web.de   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#include "configfile.h"

#include <cstdlib>
#include <fstream>

#ifdef _WIN32
#include <direct.h>
#endif

using namespace std;

ConfigFile::ConfigFile()
{

	// Pfad und Dateinamen setzen
#ifdef _WIN32
	const char *appDataPath = getenv("AppData");
	if (appDataPath)
	{
		configFileName = appDataPath;
		configFileName += "\\pokerth\\";
		mkdir(configFileName.c_str());
	}
#else
	// hier Linux/Mac Code zur Basispfadbestimmung, z.B.
	string homePath = getenv("HOME");
	configFileName = homePath+"/.pokerth/";
	// wenn nicht existiert, erzeugen!
#endif
	configFileName += "config.xml";

	//Prüfen ob Configfile existiert --> sonst anlegen
	TiXmlDocument doc(configFileName); 
	if(!doc.LoadFile()){ createDefaultConfig(); }

	cout << readConfig("numberofplayers", "2") << "\n";

}


ConfigFile::~ConfigFile()
{
}

void ConfigFile::createDefaultConfig() {
		//Anlegen!

		TiXmlDocument doc;  
		TiXmlDeclaration* decl = new TiXmlDeclaration( "1.0", "", "" );  
		doc.LinkEndChild( decl );  
	
		TiXmlElement * root = new TiXmlElement( "PokerTH" );  
		doc.LinkEndChild( root );  		
// 		
		TiXmlElement * config;
       		config = new TiXmlElement( "Configuration" );  
		root->LinkEndChild( config );  
		config->SetAttribute("numberofplayers", 5);
		config->SetAttribute("startcash", 2000);
		config->SetAttribute("smallblind", 10);
		config->SetAttribute("gamespeed", 4);
		config->SetAttribute("showgamesettingsdialogonnewgame", 1);
		config->SetAttribute("myname", "Human Player");
		config->SetAttribute("opponent1name", "Player 1");
		config->SetAttribute("opponent2name", "Player 2");
		config->SetAttribute("opponent3name", "Player 3");
		config->SetAttribute("opponent4name", "Player 4");
		config->SetAttribute("showtoolbox", 1);
		  
		doc.SaveFile( configFileName );

}

string ConfigFile::readConfig(string varName, string defaultvalue)
{
  	string tempString;

	TiXmlDocument doc(configFileName); 
	TiXmlHandle docHandle( &doc );		

	TiXmlElement* conf = docHandle.FirstChild( "PokerTH" ).FirstChild( "Configuration" ).ToElement();
	if ( conf ) {
		cout << "ich war hier" << "\n";
		conf->QueryValueAttribute(varName, &tempString );
        }
	cout << tempString << "\n";
	return tempString;
// 	QDir configDir;
// 	configDir.setPath(QDir::home().absPath()+"/.pokerth/");
// 	
// 	QFile configFile (configDir.absPath()+"/pokerth.conf");
// 	
// 	if ( !configFile.exists() ) {
// 		configFile.open( QIODevice::WriteOnly );   
// 		QTextStream stream( &configFile );
// 		stream << "##################################################################################### \n";
// 		stream << "#                                                                                   # \n";
// 		stream << "#         This is the config-file for Pokerth - Please do not edit                  # \n";
// 		stream << "#                                                                                   # \n";
// 		stream << "##################################################################################### \n";
// 		stream << "\n";
// 		stream << "numberofplayers=5\n";
// 		stream << "startcash=2000\n";
// 		stream << "smallblind=10\n";
// 		stream << "gamespeed=4\n";
// 		stream << "showgamesettingsdialogonnewgame=1\n";
// 		stream << "myname=Human Player\n";
// 		stream << "opponent1name=Player 1\n";
// 		stream << "opponent2name=Player 2\n";
// 		stream << "opponent3name=Player 3\n";
// 		stream << "opponent4name=Player 4\n";
// 		stream << "showtoolbox=1\n";
// 		configFile.close();
// 	} 
// 	
// 	QString tempstring;
// 	QString line;
// 	int foundvarname(0);
// 	
// 	configFile.open( QIODevice::ReadOnly );  
// 	QTextStream readStream( &configFile );
// 	while ( !readStream.atEnd() ) {
// 		line = readStream.readLine();
// 		if ( line.section( "=", 0, 0 ) == varName ) {
// 		tempstring = line.section( "=", 1, 1 );
// 		foundvarname++;
// 		}
// 	}
// 	configFile.close();
// 	
// 	if (foundvarname == 0) {
// 
// 		QDir configDir;
// 		configDir.setPath(QDir::home().absPath()+"/.pokerth/");
// 		
// 		QFile configFile (configDir.absPath()+"/pokerth.conf");
// 		
// 		QStringList lines;
// 		QString line;
// 		QString listtemp;
// 	
// 		if ( configFile.open( QIODevice::ReadOnly ) ) {
// 		QTextStream stream( &configFile );
// 		while ( !stream.atEnd() ) {
// 			line = stream.readLine();
// 			lines += line;
// 	
// 		}
// 		configFile.close();
// 		}
// 	
// 		if ( configFile.open( QIODevice::WriteOnly ) ) {
// 			
// 			QTextStream stream( &configFile );
// 			
// 			for ( QStringList::Iterator it = lines.begin(); it != lines.end(); ++it ) {
// 			stream << *it << "\n";
// 			}
// 			stream << varName+"="+defaultvalue+"\n";
// 			configFile.close();
// 		}
// 	
// 		tempstring = defaultvalue;    
// 
// 	}
// 

    
 }

void ConfigFile::writeConfig(string setVarName, string setVarCont)
 {
//     QDir configDir;
//     configDir.setPath(QDir::home().absPath()+"/.pokerth/");
//     QFile configFile (configDir.absPath()+"/pokerth.conf");
//  
//     QStringList lines;
//     QString line;
//     QString listtemp;
//         
//     if ( configFile.open( QIODevice::ReadOnly ) ) {
//        QTextStream stream( &configFile );
//        while ( !stream.atEnd() ) {
//           line = stream.readLine();
//           lines += line;
//        }
//        configFile.close();
//     }
//     
//     listtemp = lines.grep(QRegExp("^"+setVarName)).join("");
//     lines.gres(listtemp,setVarName+"="+setVarCont);
//     
//     if ( configFile.open( QIODevice::WriteOnly ) ) {
//         QTextStream stream( &configFile );
//         for ( QStringList::Iterator it = lines.begin(); it != lines.end(); ++it ) {
// 	   stream << *it << "\n";
//            }
// 	configFile.close();
//     }
        
}
