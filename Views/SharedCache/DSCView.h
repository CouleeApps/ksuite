//
// Created by kat on 5/23/23.
//

#ifndef KSUITE_DSCVIEW_H
#define KSUITE_DSCVIEW_H

#include <binaryninjaapi.h>

class DSCRawView : public BinaryNinja::BinaryView {
    std::string m_filename;
public:

    DSCRawView(const std::string &typeName, BinaryView *data, bool parseOnly = false);

    bool Init() override;
};


class DSCRawViewType : public BinaryNinja::BinaryViewType {

public:
    BinaryNinja::Ref<BinaryNinja::BinaryView> Create(BinaryNinja::BinaryView* data) override;
    BinaryNinja::Ref<BinaryNinja::BinaryView> Parse(BinaryNinja::BinaryView* data) override;
    bool IsTypeValidForData(BinaryNinja::BinaryView *data) override;

    bool IsDeprecated() override { return false; }

    BinaryNinja::Ref<BinaryNinja::Settings> GetLoadSettingsForData(BinaryNinja::BinaryView *data) override { return nullptr; }

public:
    DSCRawViewType();
};


class DSCView : public BinaryNinja::BinaryView {

public:

    DSCView(const std::string &typeName, BinaryView *data, bool parseOnly = false);

    bool Init() override;
};


class DSCViewType : public BinaryNinja::BinaryViewType {

public:
    DSCViewType();

    BinaryNinja::Ref<BinaryNinja::BinaryView> Create(BinaryNinja::BinaryView *data) override;

    BinaryNinja::Ref<BinaryNinja::BinaryView> Parse(BinaryNinja::BinaryView *data) override;

    bool IsTypeValidForData(BinaryNinja::BinaryView *data) override;

    bool IsDeprecated() override { return false; }

    BinaryNinja::Ref<BinaryNinja::Settings> GetLoadSettingsForData(BinaryNinja::BinaryView *data) override { return nullptr; }
};


#endif //KSUITE_DSCVIEW_H
