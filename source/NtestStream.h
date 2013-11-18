// Copyright Chris Welty
//	All Rights Reserved
// This file is distributed subject to GNU GPL version 2. See the files
// Copying.txt and GPL.txt for details.

#pragma once

#include "ggsstream.h"
#include "OsObjects.h"
#include "OsMessage.h"

class CPlayerComputer;

class CNtestStream: public ggsstream {
public:
	CNtestStream();

	virtual void HandleGGS				(const CMsg& msg);
	virtual void HandleGGSLogin			();
	virtual void HandleGGSTell			(const CMsgGGSTell& msg);
	virtual void HandleGGSUnknown		(const CMsgGGSUnknown& msg);

	virtual void HandleOsGameOver		(const CMsgOsMatchDelta& msg, const string& idg);
	virtual void HandleOsJoin			(const CMsgOsJoin& msg);
	virtual void HandleOsMatchDelta		(const CMsgOsMatchDelta& msg);
	virtual void HandleOsRequestDelta	(const CMsgOsRequestDelta& msg);
	virtual void HandleOsUnknown		(const CMsgOsUnknown& msg);
	virtual void HandleOsUpdate			(const CMsgOsUpdate& msg);

	virtual void MakeMoveIfNeeded(const string& idg);

	void SetComputer(CPlayerComputer& computer);
	CPlayerComputer* PComputer() const { return m_pComputer; };

	std::string sSuperuser;

private:
	CPlayerComputer* m_pComputer;
};
