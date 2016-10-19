# Gossip-Style-Membership-Protocol
Implementation of a Distributed System's Membership Protocol as Gossip Style heart beating

This MP (Machine Programming assignment) is about implementing a membership protocol in a distributed system. Since it is infeasible to run a thousand cluster nodes (peers) over a real network, an implementation of an emulated network layer (EmulNet) is provided beforehand. Membership protocol implementation will sit above EmulNet in a peer- to-peer (P2P) layer, but below an App layer. Actually, the system can be treated as a three-layer protocol stack with Application, P2P, and EmulNet as the three layers (from top to bottom).

The protocol was designed to satisfy: i) Completeness all the time: every non-faulty process must detect every node join, failure, and leave, and ii) Accuracy of failure detection when there are no message losses and message delays are small. When there are message losses, completeness must be satisfied and accuracy must be high. It must achieve all of these even under simultaneous multiple failures.

Among the mainstream membership protocols such as all-to-all heartbeating, gossip-style heartbeating, or SWIM-style membership, gossip-style heartbeating was particularly selected in this project for consideration of higher completeness and accuracy.

To compile the code, run make.
To execute the program, from the program directory run: ./Application testcases/<test_name>.conf. The conf files contain information about the parameters used by your application:
MAX_NNB: val
SINGLE_FAILURE: val DROP MSG: val
MSG_DROP_PROB: val
where MAX_NNB represents the max number of neighbors, SINGLE_FAILURE is a one bit 1/0 variable that setssingle/multifailurescenarios,MSG_DROP_PROB representsthemessagedropprobability(between0 and 1) and MSG_DROP is a one bit 1/0 variable that decides if messages will be dropped or not.
There is a grader script Grader.sh. It tests the implementation of membership protocol in 3 scenarios and grades each of them on 3 separate metrics. The scenarios are as follows:
1. Single node failure
2. Multiple node failure
3. Single node failure under a lossy network.
Thegraderteststhefollowingthings:i)whetherallnodesjoinedthepeergroup correctly,ii)whetherall nodes detected the failed node (completeness) and iii) whether the correct failed node was detected (accuracy). Each of these is represented as configuration files inside the testcases folder.
