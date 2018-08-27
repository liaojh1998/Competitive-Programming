#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	//Initialize
	int N, K;
	cin >> N >> K;
	long long upvotes[N+5];
	for(int i = 0; i < N; i++)
		cin >> upvotes[i];
	queue<int> last_increase_queue;
	queue<int> last_decrease_queue;

	//Initial sum
	long long sum = 0, increase_start = 0, decrease_start = 0;
	for(int i = 1; i < K; i++){
		//Non-decrease fail
		if(upvotes[i-1] > upvotes[i]){
			long long length = i - increase_start;
			sum += (length * (length + 1)) >> 1;
			last_increase_queue.push(i-1);
			increase_start = i;
		}
		//Non-increase fail
		if(upvotes[i-1] < upvotes[i]){
			long long length = i - decrease_start;
			sum -= (length * (length + 1)) >> 1;
			last_decrease_queue.push(i-1);
			decrease_start = i;
		}
	}
	long long last_increase_length = K - increase_start;
	long long last_decrease_length = K - decrease_start;
	sum += (last_increase_length * (last_increase_length + 1)) >> 1;
	sum -= (last_decrease_length * (last_decrease_length + 1)) >> 1;
	cout << sum << endl;

	//Transition
	for(int i = K; i < N; i++){
		long long start = i - K + 1;
		//Right summation
		if(upvotes[i-1] > upvotes[i]){
			//New non-decrease start point
			increase_start = i;
			last_increase_queue.push(i-1);
		}else{
			//Remove previous summation
			last_increase_length = i - increase_start;
			sum -= (last_increase_length * (last_increase_length + 1)) >> 1;
			//Adjust window
			if(increase_start < start)
				increase_start = start;
		}
		if(upvotes[i-1] < upvotes[i]){
			//New non-increase start point
			decrease_start = i;
			last_decrease_queue.push(i-1);
		}else{
			//Remove previous summation
			last_decrease_length = i - decrease_start;
			sum += (last_decrease_length * (last_decrease_length + 1)) >> 1;
			//Adjust window
			if(decrease_start < start)
				decrease_start = start;
		}
		//New right summation
		long long increase_length = i - increase_start + 1;
		long long decrease_length = i - decrease_start + 1;
		sum += (increase_length * (increase_length + 1)) >> 1;
		sum -= (decrease_length * (decrease_length + 1)) >> 1;
		//Left summation
		if(!last_increase_queue.empty()){
			//Non-decrease summation removal
			long long past_increase_length = last_increase_queue.front() - (start - 1) + 1;
			sum -= (past_increase_length * (past_increase_length + 1)) >> 1;
			//Non-decrease new summation
			long long old_increase_length = last_increase_queue.front() - start + 1;
			sum += (old_increase_length * (old_increase_length + 1)) >> 1;
			if(last_increase_queue.front() == start - 1)
				last_increase_queue.pop();
		}
		if(!last_decrease_queue.empty()){
			//Non-increase summation removal
			long long past_decrease_length = last_decrease_queue.front() - (start - 1) + 1;
			sum += (past_decrease_length * (past_decrease_length + 1)) >> 1;
			//Non-increase new summation
			long long old_decrease_length = last_decrease_queue.front() - start + 1;
			sum -= (old_decrease_length * (old_decrease_length + 1)) >> 1;
			if(last_decrease_queue.front() == start - 1)
				last_decrease_queue.pop();
		}
		cout << sum << endl;
	}

	return 0;
}