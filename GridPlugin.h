#pragma once

#include "B5Plugin.h"
#include "PluginRevisions.h"

#include "PluginOptionList.h"
#include "PluginImageSettings.h"

#include <QString>
#include <QObject>

#define PLUGINNAME	"Grid"				// The  plugin group/owner name  for all of yout plug-in's settings keep it short but unique
#define PLUGINGROUP	"Grid_kb"

//	Define here the names and IDs of your controls. 
//	Note that the buttons don't need IDs
#define BB_THIRDS		"thirds"			// Boolean - Thirds
#define BB_GOLDENRAT	"goldenrat"			// Boolean - Golden section
#define BB_GOLDENSPIR	"goldenspir"		// Boolean - Golden spiral
#define BB_SQUAREGRID	"squaregrid"		// Boolean - Golden spiral
#define BB_SPIRALCENTER	"spiralcenter"		// Integer - Spiral center position
#define BB_GRIDSIZE		"gridsize"			// Integer - Square grid size
#define BB_GRIDXCENTER	"gridxcenter"		// Integer - Square grid center position
#define BB_GRIDYCENTER	"gridycenter"		// Integer - Square grid center position
#define BB_COLORSCHEME	"colorscheme"		// Integer - Color scheme

#define ID_GOLDENRAT	20
#define ID_GOLDENSPIR	21
#define ID_SQUAREGRID	22
#define ID_THIRDS		23
#define ID_SPIRALCENTER	25
#define ID_GRIDSIZE		27
#define ID_GRIDXCENTER	28
#define ID_GRIDYCENTER	29
#define ID_COLORCHEME	35

#define BB_ABOUT	"about_button"				// About button

//	The Plugin class
class GridPlugin : public QObject, public B5Plugin
{
        Q_OBJECT

public:
	GridPlugin() : m_hub( NULL ), m_id( -1 ), m_groupId( -1 ), m_pWindow( NULL ) { ; }
	virtual int priority() { return 12; }
	virtual QString name() { return QString(PLUGINNAME); }
	virtual QString group() { return QString(PLUGINGROUP); }
	virtual bool init(PluginHub *hub, int id, int groupId, const QString &bundlePath);
	virtual bool registerFilters();
	virtual bool registerOptions();
	virtual bool finish();
	virtual PluginDependency *createDependency(const QString &name);
	virtual QList<QString> toolFiles();
	virtual QList<QWidget*> toolWidgets();
	virtual void toolWidgetCreated(QWidget *uiWidget);

private slots:
	void showAbout() const;
	void handleControlChange(const QString &optionName, int groupId, int layer, const PluginImageSettings &options, const PluginOptionList &current, PluginOptionList &changes);

private:
	PluginHub *m_hub;
	int m_id;
	int m_groupId;
	QWidget *m_pWindow;
};
