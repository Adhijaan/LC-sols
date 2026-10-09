from collections import defaultdict
class Solution(object):
    def leastInterval(self, tasks, n):
        """
        :type tasks: List[str]
        :type n: int
        :rtype: int
        """
        if n == 0:
            return len(tasks)

        # Map task frequency
        freq = defaultdict(int)
        for t in tasks:
            freq[t] += 1
        

        sorted_task_len = sorted(freq.values())

        max_freq = sorted_task_len[-1]
        num_max = sorted_task_len.count(max_freq)

        return max(
            len(tasks),
            (max_freq - 1) * (n + 1) + num_max
        )


