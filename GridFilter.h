#pragma once

#include "PluginFilter.h"
#include "PluginHub.h"

#include "cshapes.h"

#define FILTERNAME      "GridFilter"

typedef unsigned short uint16; 

// This is a filter class
// Probably you don't have to change much here...

class GridFilter : public PluginFilter
{
public:
	GridFilter(PluginHub *hub, int groupId) : m_hub(hub), m_groupId(groupId) { ; }

	virtual QString name() const { return QString(FILTERNAME); }

	virtual bool needsToRun(const PluginImageSettings &options, const PluginPipeSettings &settingss) const;
	virtual void run(const PluginImageSettings &options, const PluginPipeSettings &settings, PluginTile &tile) const;
	virtual bool needsOriginalImage() { return false; }

	virtual bool isSlow(const PluginImageSettings &, const PluginPipeSettings &) const { return false; }
	virtual bool isLargeRadius(const PluginImageSettings &, const PluginPipeSettings &) const { return false; }
	virtual bool isPixelSource(const PluginImageSettings &, const PluginPipeSettings &) const { return false; }
	virtual QTransform transform(const PluginImageSettings &options, const PluginPipeSettings &settings, const QSize &startSize) const;
	virtual QSize size(const PluginImageSettings &options, const PluginPipeSettings &settings, const QSize &startSize) const;
	virtual QList<PluginDependency*> prerequisites(const PluginImageSettings &options, const PluginPipeSettings &settings, PluginTile &tile) const;

private:
	PluginHub *m_hub;
	int m_groupId;
	void drawgoldenrat(int left,int top,int right,int bottom,CShapes csh) const;
	void drawthirds(int left,int top,int right,int bottom,CShapes csh) const;
	void drawgoldenspiral1(int left,int top,int right,int bottom,int dir,int depth,CShapes csh) const;
	void drawgoldenspiral2(int left,int top,int right,int bottom,int dir,int depth,CShapes csh) const;
	void drawgoldendiag(int left,int top,int right,int bottom,int dir,uint16 LC,uint16 SC,CShapes csh) const;
};
