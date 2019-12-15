/***

  Olive - Non-Linear Video Editor
  Copyright (C) 2019 Olive Team

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.

***/

#ifndef VIEWER_PANEL_H
#define VIEWER_PANEL_H

#include <QOpenGLFunctions>

#include "widget/panel/panel.h"
#include "widget/viewer/viewer.h"

/**
 * @brief Dockable wrapper around a ViewerWidget
 */
class ViewerPanel : public PanelWidget {
  Q_OBJECT
public:
  ViewerPanel(QWidget* parent);

  virtual void ZoomIn() override;

  virtual void ZoomOut() override;

  virtual void GoToStart() override;

  virtual void PrevFrame() override;

  virtual void PlayPause() override;

  virtual void NextFrame() override;

  virtual void GoToEnd() override;

  virtual void ShuttleLeft() override;

  virtual void ShuttleStop() override;

  virtual void ShuttleRight() override;

  void SetTimebase(const rational& timebase);

  void ConnectViewerNode(ViewerOutput* node);

  void DisconnectViewerNode();

  rational GetTime();

  ViewerOutput* GetConnectedViewer() const;

public slots:
  void SetTime(const int64_t& timestamp);

protected:
  virtual void changeEvent(QEvent* e) override;

signals:
  void TimeChanged(const int64_t&);

private:
  void Retranslate();

  ViewerWidget* viewer_;
};

#endif // VIEWER_PANEL_H
