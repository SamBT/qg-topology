C     This File is Automatically generated by ALOHA 
C     The process calculated in this file is: 
C     P(1,2)*P(2,1) - P(-1,1)*P(-1,2)*Metric(1,2)
C     
      SUBROUTINE VVS3P0_1(V2, S3, COUP, M1, W1,V1)
      IMPLICIT NONE
      COMPLEX*16 CI
      PARAMETER (CI=(0D0,1D0))
      COMPLEX*16 V2(*)
      COMPLEX*16 DENOM
      COMPLEX*16 S3(*)
      REAL*8 P1(0:3)
      REAL*8 M1
      COMPLEX*16 TMP10
      REAL*8 P2(0:3)
      REAL*8 W1
      COMPLEX*16 TMP5
      COMPLEX*16 COUP
      COMPLEX*16 V1(6)
      P2(0) = DBLE(V2(1))
      P2(1) = DBLE(V2(2))
      P2(2) = DIMAG(V2(2))
      P2(3) = DIMAG(V2(1))
      V1(1) = +V2(1)+S3(1)
      V1(2) = +V2(2)+S3(2)
      P1(0) = -DBLE(V1(1))
      P1(1) = -DBLE(V1(2))
      P1(2) = -DIMAG(V1(2))
      P1(3) = -DIMAG(V1(1))
      TMP5 = (P1(0)*V2(3)-P1(1)*V2(4)-P1(2)*V2(5)-P1(3)*V2(6))
      TMP10 = (P1(0)*P2(0)-P1(1)*P2(1)-P1(2)*P2(2)-P1(3)*P2(3))
      DENOM = COUP/(P1(0)**2-P1(1)**2-P1(2)**2-P1(3)**2 - M1 * (M1 -CI
     $ * W1))
      V1(3)= DENOM*S3(3)*(-CI*(P2(0)*TMP5)+CI*(V2(3)*TMP10))
      V1(4)= DENOM*S3(3)*(-CI*(P2(1)*TMP5)+CI*(V2(4)*TMP10))
      V1(5)= DENOM*S3(3)*(-CI*(P2(2)*TMP5)+CI*(V2(5)*TMP10))
      V1(6)= DENOM*S3(3)*(-CI*(P2(3)*TMP5)+CI*(V2(6)*TMP10))
      END


