xof 0303txt 0032

template XSkinMeshHeader {
  <3cf169ce-ff7c-44ab-93c0-f78f62d172e2>
  WORD nMaxSkinWeightsPerVertex;
  WORD nMaxSkinWeightsPerFace;
  WORD nBones;
}

template SkinWeights {
  <6f0d123b-bad2-4167-a0d0-80224f25fabb>
  STRING transformNodeName;
  DWORD nWeights;
  array DWORD vertexIndices[nWeights];
  array float weights[nWeights];
  Matrix4x4 matrixOffset;
}

Frame Root {
  FrameTransformMatrix {
     1.000000, 0.000000, 0.000000, 0.000000,
     0.000000, 0.000000, 1.000000, 0.000000,
     0.000000, 1.000000,-0.000000, 0.000000,
     0.000000, 0.000000, 0.000000, 1.000000;;
  }
  Frame Cube {
    FrameTransformMatrix {
       1.000000, 0.000000, 0.000000, 0.000000,
       0.000000, 1.000000, 0.000000, 0.000000,
       0.000000, 0.000000, 1.000000, 0.000000,
       0.000000, 0.000000, 0.000000, 1.000000;;
    }
    Mesh { //Cube_001 Mesh
      4;
       0.999999;-1.000001; 0.000011;,
      -1.000000;-1.000000; 0.000011;,
      -1.000000; 1.000000; 0.000011;,
       1.000000; 0.999999; 0.000011;;
      1;
      4;0;1;2;3;;
      MeshNormals { //Cube_001 Normals
        4;
         0.000000;-0.000000; 1.000000;,
         0.000000;-0.000000; 1.000000;,
         0.000000;-0.000000; 1.000000;,
         0.000000;-0.000000; 1.000000;;
        1;
        4;0;1;2;3;;
      } //End of Cube_001 Normals
      MeshMaterialList { //Cube_001 Material List
        1;
        1;
        0;;
        Material Material {
           0.640000; 0.640000; 0.640000; 1.000000;;
           96.078431;
           0.500000; 0.500000; 0.500000;;
           0.000000; 0.000000; 0.000000;;
        }
      } //End of Cube_001 Material List
    } //End of Cube_001 Mesh
  } //End of Cube
} //End of Root Frame
AnimationSet {
  Animation {
    {Cube}
    AnimationKey { //Position
      2;
      2;
      0;3;     0.000000, 0.000000, 0.000000;;,
      24;3;    0.000000, 0.000000, 0.000000;;;
    }
    AnimationKey { //Rotation
      0;
      2;
      0;4;    -1.000000, 0.000000, 0.000000, 0.000000;;,
      24;4;    0.999979,-0.000000, 0.000000,-0.006468;;;
    }
    AnimationKey { //Scale
      1;
      2;
      0;3;     1.000000, 1.000000, 1.000000;;,
      24;3;    1.000000, 1.000000, 1.000000;;;
    }
  }
} //End of AnimationSet
