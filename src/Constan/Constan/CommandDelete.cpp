#include "CommandDelete.h"

CommandDelete::CommandDelete(int index) {
	_index = index;
	_currentDisplay = currentDisplay;
}

CommandDelete::~CommandDelete(void)
{
}

void CommandDelete::execute() {
	_taskId = _currentDisplay->at(_index-1).getTaskId();
	_taskName = _currentDisplay->at(_index-1).getTaskName();
	TaskManager::getInstance()->deleteTask(_taskId);
    
}

void CommandDelete::updateDisplay(vector<Task>* currentDisplay) {
	_timedTaskVector = TaskManager::getInstance()->retrieveTimedTask("29 March 2015");
	_deadlineVector  = TaskManager::getInstance()->retrieveDeadline("29 March 2015");
	_mergedDisplay = new vector<Task>;
	merge (_timedTaskVector.begin(), _timedTaskVector.end(), _deadlineVector.begin(), _deadlineVector.end(), _mergedDisplay.begin(), Compare_Task());
	currentDisplay = _mergedDisplay;
}

void CommandDelete::updateFeedback(vector<string>* feedbackVector) {
	_feedback = new vector<string>; 
	_feedback->push_back (_taskName);
	_feedback->push_back ("delete");
	feedbackVector = _feedback;
	
}

/*Command CommandDelete::getInverseCommand() {
	//get info;
	CommandAdd invDelete(std::string taskName, std::string startTime, std::string endTime, bool isCompleted);
	return invDelete;
}*/