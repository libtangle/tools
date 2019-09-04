

// class GraphState(object):
//   def __init__(self, num_nodes):
//     self.vertices = []

//     for i in range(num_nodes):
//       self.vertices.append(QubitVertex())

// class QubitVertex(object):
//   def __init__(self):
//     self.vop_code = 10
//     self.neighbors = set()

class QubitVertex {
  int vop_code;

 public:
  QubitVertex() : vop_code(10) {}
  QubitVertex(int vop) : vop_code(vop) {}
};

class GraphState {
 public:
};
