# LTE-X2-link-dim
X2 link dimensioning

The X2 interface connects directly two neighboring evolved NodeBs. One of its main responsibilities is to transfer the user-plane and control-plane data during a handover. 

It is assumed that calls arrive in the X2 link according to a Poisson process and compete for the available bandwidth. A call is accepted in the system if its bandwidth requirement is available. Otherwise, the call is blocked and lost without further affecting the system.

Calculate either the blocking probabilities for a given link capacity or the required capacity for specified target blocking probabilities.
