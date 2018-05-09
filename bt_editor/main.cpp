#include <QCommandLineParser>
#include <QApplication>
#include <nodes/NodeStyle>
#include <nodes/FlowViewStyle>
#include <nodes/ConnectionStyle>

#include "models/ControlNodeModel.hpp"
#include "mainwindow.h"
#include "models/ActionNodeModel.hpp"
#include "models/RootNodeModel.hpp"
#include "NodeFactory.hpp"

#include <nodes/DataModelRegistry>
#include "XmlParsers.hpp"

#ifdef USING_ROS
#include <ros/ros.h>
#endif

using QtNodes::DataModelRegistry;
using QtNodes::FlowViewStyle;
using QtNodes::NodeStyle;
using QtNodes::ConnectionStyle;

int
main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  app.setApplicationName("BehaviorTreeEditor");

  QCommandLineParser parser;
  parser.setApplicationDescription("BehaviorTreeEditor: just a fancy XMl editor");
  parser.addHelpOption();

  QCommandLineOption test_option(QStringList() << "t" << "test",
                                 QCoreApplication::translate("main", "Load dummy"));
  parser.addOption(test_option);
  parser.process( app );

  // EditorModel::loadMetaModelFromFile( "/home/dfaconti/ExampeEditorMetaModel.xml" );

  MainWindow win;

  if( parser.isSet(test_option) )
  {
    win.loadFromXML( gTestXML );
  }

  win.show();

  return app.exec();
}