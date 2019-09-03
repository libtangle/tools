OPENQASM 2.0;

creg c[3];
qreg q[3];

gate id a { U(0,0,0) a; }
// 3-parameter 2-pulse single qubit gate
gate u3(theta,phi,lambda) q { U(theta,phi,lambda) q; }