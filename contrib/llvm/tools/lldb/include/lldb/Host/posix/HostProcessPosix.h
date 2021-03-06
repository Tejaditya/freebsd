//===-- HostProcessPosix.h --------------------------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef lldb_Host_HostProcesPosix_h_
#define lldb_Host_HostProcesPosix_h_

// C Includes
// C++ Includes
// Other libraries and framework includes
// Project includes
#include "lldb/lldb-types.h"
#include "lldb/Core/Error.h"
#include "lldb/Host/HostNativeProcessBase.h"

namespace lldb_private
{

class FileSpec;

class HostProcessPosix : public HostNativeProcessBase
{
  public:
    HostProcessPosix();
    HostProcessPosix(lldb::process_t process);
    ~HostProcessPosix() override;

    virtual Error Signal(int signo) const;
    static Error Signal(lldb::process_t process, int signo);

    Error Terminate() override;
    Error GetMainModule(FileSpec &file_spec) const override;

    lldb::pid_t GetProcessId() const override;
    bool IsRunning() const override;

    HostThread
    StartMonitoring(const Host::MonitorChildProcessCallback &callback, bool monitor_signals) override;
};

} // namespace lldb_private

#endif // lldb_Host_HostProcesPosix_h_
