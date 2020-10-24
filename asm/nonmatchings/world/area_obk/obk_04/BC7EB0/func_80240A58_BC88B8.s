.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A58_BC88B8
/* BC88B8 80240A58 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* BC88BC 80240A5C AFB00010 */  sw        $s0, 0x10($sp)
/* BC88C0 80240A60 0080802D */  daddu     $s0, $a0, $zero
/* BC88C4 80240A64 24040001 */  addiu     $a0, $zero, 1
/* BC88C8 80240A68 AFBF0030 */  sw        $ra, 0x30($sp)
/* BC88CC 80240A6C AFB7002C */  sw        $s7, 0x2c($sp)
/* BC88D0 80240A70 AFB60028 */  sw        $s6, 0x28($sp)
/* BC88D4 80240A74 AFB50024 */  sw        $s5, 0x24($sp)
/* BC88D8 80240A78 AFB40020 */  sw        $s4, 0x20($sp)
/* BC88DC 80240A7C AFB3001C */  sw        $s3, 0x1c($sp)
/* BC88E0 80240A80 AFB20018 */  sw        $s2, 0x18($sp)
/* BC88E4 80240A84 0C00EABB */  jal       get_npc_unsafe
/* BC88E8 80240A88 AFB10014 */   sw       $s1, 0x14($sp)
/* BC88EC 80240A8C 24040002 */  addiu     $a0, $zero, 2
/* BC88F0 80240A90 0C00EABB */  jal       get_npc_unsafe
/* BC88F4 80240A94 0040B82D */   daddu    $s7, $v0, $zero
/* BC88F8 80240A98 24040003 */  addiu     $a0, $zero, 3
/* BC88FC 80240A9C 0C00EABB */  jal       get_npc_unsafe
/* BC8900 80240AA0 0040B02D */   daddu    $s6, $v0, $zero
/* BC8904 80240AA4 24040004 */  addiu     $a0, $zero, 4
/* BC8908 80240AA8 0C00EABB */  jal       get_npc_unsafe
/* BC890C 80240AAC 0040A82D */   daddu    $s5, $v0, $zero
/* BC8910 80240AB0 24040005 */  addiu     $a0, $zero, 5
/* BC8914 80240AB4 0C00EABB */  jal       get_npc_unsafe
/* BC8918 80240AB8 0040A02D */   daddu    $s4, $v0, $zero
/* BC891C 80240ABC 24040006 */  addiu     $a0, $zero, 6
/* BC8920 80240AC0 0C00EABB */  jal       get_npc_unsafe
/* BC8924 80240AC4 0040982D */   daddu    $s3, $v0, $zero
/* BC8928 80240AC8 24040007 */  addiu     $a0, $zero, 7
/* BC892C 80240ACC 0C00EABB */  jal       get_npc_unsafe
/* BC8930 80240AD0 0040902D */   daddu    $s2, $v0, $zero
/* BC8934 80240AD4 24040008 */  addiu     $a0, $zero, 8
/* BC8938 80240AD8 0C00EABB */  jal       get_npc_unsafe
/* BC893C 80240ADC 0040882D */   daddu    $s1, $v0, $zero
/* BC8940 80240AE0 8E030084 */  lw        $v1, 0x84($s0)
/* BC8944 80240AE4 0040302D */  daddu     $a2, $v0, $zero
/* BC8948 80240AE8 2C620008 */  sltiu     $v0, $v1, 8
/* BC894C 80240AEC 10400039 */  beqz      $v0, .L80240BD4
/* BC8950 80240AF0 00031080 */   sll      $v0, $v1, 2
/* BC8954 80240AF4 3C018024 */  lui       $at, 0x8024
/* BC8958 80240AF8 00220821 */  addu      $at, $at, $v0
/* BC895C 80240AFC 8C2251D8 */  lw        $v0, 0x51d8($at)
/* BC8960 80240B00 00400008 */  jr        $v0
/* BC8964 80240B04 00000000 */   nop      
/* BC8968 80240B08 0000202D */  daddu     $a0, $zero, $zero
/* BC896C 80240B0C 3C05FD05 */  lui       $a1, 0xfd05
/* BC8970 80240B10 34A50F85 */  ori       $a1, $a1, 0xf85
/* BC8974 80240B14 C6E0000C */  lwc1      $f0, 0xc($s7)
/* BC8978 80240B18 080902F1 */  j         .L80240BC4
/* BC897C 80240B1C 24060001 */   addiu    $a2, $zero, 1
/* BC8980 80240B20 0000202D */  daddu     $a0, $zero, $zero
/* BC8984 80240B24 3C05FD05 */  lui       $a1, 0xfd05
/* BC8988 80240B28 34A50F85 */  ori       $a1, $a1, 0xf85
/* BC898C 80240B2C C6C0000C */  lwc1      $f0, 0xc($s6)
/* BC8990 80240B30 080902F1 */  j         .L80240BC4
/* BC8994 80240B34 24060002 */   addiu    $a2, $zero, 2
/* BC8998 80240B38 0000202D */  daddu     $a0, $zero, $zero
/* BC899C 80240B3C 3C05FD05 */  lui       $a1, 0xfd05
/* BC89A0 80240B40 34A50F85 */  ori       $a1, $a1, 0xf85
/* BC89A4 80240B44 C6A0000C */  lwc1      $f0, 0xc($s5)
/* BC89A8 80240B48 080902F1 */  j         .L80240BC4
/* BC89AC 80240B4C 24060003 */   addiu    $a2, $zero, 3
/* BC89B0 80240B50 0000202D */  daddu     $a0, $zero, $zero
/* BC89B4 80240B54 3C05FD05 */  lui       $a1, 0xfd05
/* BC89B8 80240B58 34A50F85 */  ori       $a1, $a1, 0xf85
/* BC89BC 80240B5C C680000C */  lwc1      $f0, 0xc($s4)
/* BC89C0 80240B60 080902F1 */  j         .L80240BC4
/* BC89C4 80240B64 24060004 */   addiu    $a2, $zero, 4
/* BC89C8 80240B68 0000202D */  daddu     $a0, $zero, $zero
/* BC89CC 80240B6C 3C05FD05 */  lui       $a1, 0xfd05
/* BC89D0 80240B70 34A50F85 */  ori       $a1, $a1, 0xf85
/* BC89D4 80240B74 C660000C */  lwc1      $f0, 0xc($s3)
/* BC89D8 80240B78 080902F1 */  j         .L80240BC4
/* BC89DC 80240B7C 24060005 */   addiu    $a2, $zero, 5
/* BC89E0 80240B80 0000202D */  daddu     $a0, $zero, $zero
/* BC89E4 80240B84 3C05FD05 */  lui       $a1, 0xfd05
/* BC89E8 80240B88 34A50F85 */  ori       $a1, $a1, 0xf85
/* BC89EC 80240B8C C640000C */  lwc1      $f0, 0xc($s2)
/* BC89F0 80240B90 080902F1 */  j         .L80240BC4
/* BC89F4 80240B94 24060006 */   addiu    $a2, $zero, 6
/* BC89F8 80240B98 0000202D */  daddu     $a0, $zero, $zero
/* BC89FC 80240B9C 3C05FD05 */  lui       $a1, 0xfd05
/* BC8A00 80240BA0 34A50F85 */  ori       $a1, $a1, 0xf85
/* BC8A04 80240BA4 C620000C */  lwc1      $f0, 0xc($s1)
/* BC8A08 80240BA8 080902F1 */  j         .L80240BC4
/* BC8A0C 80240BAC 24060007 */   addiu    $a2, $zero, 7
/* BC8A10 80240BB0 0000202D */  daddu     $a0, $zero, $zero
/* BC8A14 80240BB4 3C05FD05 */  lui       $a1, 0xfd05
/* BC8A18 80240BB8 34A50F85 */  ori       $a1, $a1, 0xf85
/* BC8A1C 80240BBC C4C0000C */  lwc1      $f0, 0xc($a2)
/* BC8A20 80240BC0 24060008 */  addiu     $a2, $zero, 8
.L80240BC4:
/* BC8A24 80240BC4 4600008D */  trunc.w.s $f2, $f0
/* BC8A28 80240BC8 0C0B2026 */  jal       set_variable
/* BC8A2C 80240BCC E6020084 */   swc1     $f2, 0x84($s0)
/* BC8A30 80240BD0 8E030084 */  lw        $v1, 0x84($s0)
.L80240BD4:
/* BC8A34 80240BD4 8E040088 */  lw        $a0, 0x88($s0)
/* BC8A38 80240BD8 00641821 */  addu      $v1, $v1, $a0
/* BC8A3C 80240BDC AE030084 */  sw        $v1, 0x84($s0)
/* BC8A40 80240BE0 8FBF0030 */  lw        $ra, 0x30($sp)
/* BC8A44 80240BE4 8FB7002C */  lw        $s7, 0x2c($sp)
/* BC8A48 80240BE8 8FB60028 */  lw        $s6, 0x28($sp)
/* BC8A4C 80240BEC 8FB50024 */  lw        $s5, 0x24($sp)
/* BC8A50 80240BF0 8FB40020 */  lw        $s4, 0x20($sp)
/* BC8A54 80240BF4 8FB3001C */  lw        $s3, 0x1c($sp)
/* BC8A58 80240BF8 8FB20018 */  lw        $s2, 0x18($sp)
/* BC8A5C 80240BFC 8FB10014 */  lw        $s1, 0x14($sp)
/* BC8A60 80240C00 8FB00010 */  lw        $s0, 0x10($sp)
/* BC8A64 80240C04 24020002 */  addiu     $v0, $zero, 2
/* BC8A68 80240C08 03E00008 */  jr        $ra
/* BC8A6C 80240C0C 27BD0038 */   addiu    $sp, $sp, 0x38
