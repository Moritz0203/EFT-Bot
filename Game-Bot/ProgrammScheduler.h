#pragma once

typedef enum e_stash_version {
	Standard = 1,
	LeftBehind = 2,
	PrepareForEscape = 3,
	EdgeOfDarkness = 11,
}stash_version;

class ProgrammScheduler
{
	stash_version Stash_Version = EdgeOfDarkness;
	bool HasReceivedVersion = false;

	void SchedulerWorker();

public:
	stash_version GetStashVersion() const {
		return this->Stash_Version;
	}

	void Scheduler();

	void setVersion(stash_version stash_version) {
		this->Stash_Version = stash_version;
		HasReceivedVersion = true;
	}
};