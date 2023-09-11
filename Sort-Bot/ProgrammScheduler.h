#pragma once

typedef enum e_stash_version {
	Standard = 1,
	LeftBehind = 2,
	PrepareForEscape = 3,
	EdgeOfDarkness = 11,
}stash_version;


class ProgrammScheduler {
	stash_version Stash_Version = EdgeOfDarkness;
	bool HasReceivedVersion = false;

	void ScreenShots();

	void SchedulerWorker();

public:
	void Scheduler();

	void setVersion(stash_version stash_version) {
		Stash_Version = stash_version;
		HasReceivedVersion = true;
	}
};