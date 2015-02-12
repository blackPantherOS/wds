#ifndef DESKTOP_MEDIA_MANAGER_H_
#define DESKTOP_MEDIA_MANAGER_H_

#include <memory>

#include "wfd/public/media_manager.h"
#include "mirac-gst-test-source.hpp"

class DesktopMediaManager : public wfd::SourceMediaManager {
 public:
  explicit DesktopMediaManager(const std::string& hostname);
  virtual void Play() override;
  virtual void Pause() override;
  virtual void Teardown() override;
  virtual bool IsPaused() const override;
  virtual void SetSinkRtpPorts(int port1, int port2) override;
  virtual std::pair<int,int> SinkRtpPorts() const override;
  virtual int SourceRtpPort() const override;

  virtual std::vector<wfd::SelectableH264VideoFormat> GetSelectableH264VideoFormats() const override;
  virtual bool SetOptimalFormat(const wfd::SelectableH264VideoFormat& optimal_format) override;
  virtual wfd::SelectableH264VideoFormat GetOptimalFormat() const override;

 private:
  std::string hostname_;
  std::unique_ptr<MiracGstTestSource> gst_pipeline_;
  int sink_port1_;
  int sink_port2_;
  wfd::SelectableH264VideoFormat format_;
};

#endif // DESKTOP_MEDIA_MANAGER_H_
