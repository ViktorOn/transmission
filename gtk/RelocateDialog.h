// This file Copyright © 2009-2022 Mnemosyne LLC.
// It may be used under GPLv2 (SPDX: GPL-2.0-only), GPLv3 (SPDX: GPL-3.0-only),
// or any future license endorsed by Mnemosyne LLC.
// License text can be found in the licenses/ folder.

#pragma once

#include <memory>
#include <vector>

#include <gtkmm.h>

#include <libtransmission/tr-macros.h>

class Session;

class RelocateDialog : public Gtk::Dialog
{
public:
    ~RelocateDialog() override;

    TR_DISABLE_COPY_MOVE(RelocateDialog)

    static std::unique_ptr<RelocateDialog> create(
        Gtk::Window& parent,
        Glib::RefPtr<Session> const& core,
        std::vector<tr_torrent_id_t> const& torrent_ids);

protected:
    RelocateDialog(Gtk::Window& parent, Glib::RefPtr<Session> const& core, std::vector<tr_torrent_id_t> const& torrent_ids);

private:
    class Impl;
    std::unique_ptr<Impl> const impl_;
};
