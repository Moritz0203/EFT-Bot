#pragma once

typedef enum e_stash_version {
	Standard = 1,
	LeftBehind = 2,
	PrepareForEscape = 3,
	EdgeOfDarkness = 11,
}stash_version;

class LobbyControler {
	stash_version Stash_Version = EdgeOfDarkness;

	void StashControler();
	void ServerControler();
	void QueueControler();

	void OpenStashView();

public:
	stash_version GetStashVersion() const {
		return this->Stash_Version;
	}

	void setVersion(stash_version stash_version) {
		this->Stash_Version = stash_version;
	}

	void TakeScreenShots();
	void Controler();
};
