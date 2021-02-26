.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80064940
/* 3FD40 80064940 00041823 */  negu      $v1, $a0
/* 3FD44 80064944 28A1000C */  slti      $at, $a1, 0xc
/* 3FD48 80064948 1420001D */  bnez      $at, .L800649C0
/* 3FD4C 8006494C 00000000 */   nop
/* 3FD50 80064950 30630003 */  andi      $v1, $v1, 3
/* 3FD54 80064954 10600003 */  beqz      $v1, .L80064964
/* 3FD58 80064958 00A32823 */   subu     $a1, $a1, $v1
/* 3FD5C 8006495C A8800000 */  swl       $zero, ($a0)
/* 3FD60 80064960 00832021 */  addu      $a0, $a0, $v1
.L80064964:
/* 3FD64 80064964 2401FFE0 */  addiu     $at, $zero, -0x20
/* 3FD68 80064968 00A13824 */  and       $a3, $a1, $at
/* 3FD6C 8006496C 10E0000C */  beqz      $a3, .L800649A0
/* 3FD70 80064970 00A72823 */   subu     $a1, $a1, $a3
/* 3FD74 80064974 00E43821 */  addu      $a3, $a3, $a0
.L80064978:
/* 3FD78 80064978 AC800000 */  sw        $zero, ($a0)
/* 3FD7C 8006497C AC800004 */  sw        $zero, 4($a0)
/* 3FD80 80064980 AC800008 */  sw        $zero, 8($a0)
/* 3FD84 80064984 AC80000C */  sw        $zero, 0xc($a0)
/* 3FD88 80064988 24840020 */  addiu     $a0, $a0, 0x20
/* 3FD8C 8006498C AC80FFF0 */  sw        $zero, -0x10($a0)
/* 3FD90 80064990 AC80FFF4 */  sw        $zero, -0xc($a0)
/* 3FD94 80064994 AC80FFF8 */  sw        $zero, -8($a0)
/* 3FD98 80064998 1487FFF7 */  bne       $a0, $a3, .L80064978
/* 3FD9C 8006499C AC80FFFC */   sw       $zero, -4($a0)
.L800649A0:
/* 3FDA0 800649A0 2401FFFC */  addiu     $at, $zero, -4
/* 3FDA4 800649A4 00A13824 */  and       $a3, $a1, $at
/* 3FDA8 800649A8 10E00005 */  beqz      $a3, .L800649C0
/* 3FDAC 800649AC 00A72823 */   subu     $a1, $a1, $a3
/* 3FDB0 800649B0 00E43821 */  addu      $a3, $a3, $a0
.L800649B4:
/* 3FDB4 800649B4 24840004 */  addiu     $a0, $a0, 4
/* 3FDB8 800649B8 1487FFFE */  bne       $a0, $a3, .L800649B4
/* 3FDBC 800649BC AC80FFFC */   sw       $zero, -4($a0)
.L800649C0:
/* 3FDC0 800649C0 18A00005 */  blez      $a1, .L800649D8
/* 3FDC4 800649C4 00000000 */   nop
/* 3FDC8 800649C8 00A42821 */  addu      $a1, $a1, $a0
.L800649CC:
/* 3FDCC 800649CC 24840001 */  addiu     $a0, $a0, 1
/* 3FDD0 800649D0 1485FFFE */  bne       $a0, $a1, .L800649CC
/* 3FDD4 800649D4 A080FFFF */   sb       $zero, -1($a0)
.L800649D8:
/* 3FDD8 800649D8 03E00008 */  jr        $ra
/* 3FDDC 800649DC 00000000 */   nop
