.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004DC84
/* 29084 8004DC84 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 29088 8004DC88 AFB3001C */  sw        $s3, 0x1c($sp)
/* 2908C 8004DC8C 0080982D */  daddu     $s3, $a0, $zero
/* 29090 8004DC90 24060A9C */  addiu     $a2, $zero, 0xa9c
/* 29094 8004DC94 AFBF0024 */  sw        $ra, 0x24($sp)
/* 29098 8004DC98 AFB40020 */  sw        $s4, 0x20($sp)
/* 2909C 8004DC9C AFB20018 */  sw        $s2, 0x18($sp)
/* 290A0 8004DCA0 AFB10014 */  sw        $s1, 0x14($sp)
/* 290A4 8004DCA4 AFB00010 */  sw        $s0, 0x10($sp)
/* 290A8 8004DCA8 8E710074 */  lw        $s1, 0x74($s3)
/* 290AC 8004DCAC 8E640078 */  lw        $a0, 0x78($s3)
/* 290B0 8004DCB0 0C015309 */  jal       func_80054C24
/* 290B4 8004DCB4 0220282D */   daddu    $a1, $s1, $zero
/* 290B8 8004DCB8 8E63007C */  lw        $v1, 0x7c($s3)
/* 290BC 8004DCBC 8E22001C */  lw        $v0, 0x1c($s1)
/* 290C0 8004DCC0 54620030 */  bnel      $v1, $v0, .L8004DD84
/* 290C4 8004DCC4 AE600080 */   sw       $zero, 0x80($s3)
/* 290C8 8004DCC8 0000302D */  daddu     $a2, $zero, $zero
/* 290CC 8004DCCC 2405025C */  addiu     $a1, $zero, 0x25c
.L8004DCD0:
/* 290D0 8004DCD0 02259021 */  addu      $s2, $s1, $a1
/* 290D4 8004DCD4 8E420000 */  lw        $v0, ($s2)
/* 290D8 8004DCD8 50400011 */  beql      $v0, $zero, .L8004DD20
/* 290DC 8004DCDC 24C60001 */   addiu    $a2, $a2, 1
/* 290E0 8004DCE0 92430052 */  lbu       $v1, 0x52($s2)
/* 290E4 8004DCE4 92420053 */  lbu       $v0, 0x53($s2)
/* 290E8 8004DCE8 0062102B */  sltu      $v0, $v1, $v0
/* 290EC 8004DCEC 1040000B */  beqz      $v0, .L8004DD1C
/* 290F0 8004DCF0 00031040 */   sll      $v0, $v1, 1
/* 290F4 8004DCF4 00431021 */  addu      $v0, $v0, $v1
/* 290F8 8004DCF8 000210C0 */  sll       $v0, $v0, 3
/* 290FC 8004DCFC 2444085C */  addiu     $a0, $v0, 0x85c
.L8004DD00:
/* 29100 8004DD00 02241021 */  addu      $v0, $s1, $a0
/* 29104 8004DD04 AC40000C */  sw        $zero, 0xc($v0)
/* 29108 8004DD08 92420053 */  lbu       $v0, 0x53($s2)
/* 2910C 8004DD0C 24630001 */  addiu     $v1, $v1, 1
/* 29110 8004DD10 0062102B */  sltu      $v0, $v1, $v0
/* 29114 8004DD14 1440FFFA */  bnez      $v0, .L8004DD00
/* 29118 8004DD18 24840018 */   addiu    $a0, $a0, 0x18
.L8004DD1C:
/* 2911C 8004DD1C 24C60001 */  addiu     $a2, $a2, 1
.L8004DD20:
/* 29120 8004DD20 2CC20010 */  sltiu     $v0, $a2, 0x10
/* 29124 8004DD24 1440FFEA */  bnez      $v0, .L8004DCD0
/* 29128 8004DD28 24A50060 */   addiu    $a1, $a1, 0x60
/* 2912C 8004DD2C 0000802D */  daddu     $s0, $zero, $zero
/* 29130 8004DD30 241400FF */  addiu     $s4, $zero, 0xff
/* 29134 8004DD34 02301821 */  addu      $v1, $s1, $s0
.L8004DD38:
/* 29138 8004DD38 9062004C */  lbu       $v0, 0x4c($v1)
/* 2913C 8004DD3C 50540008 */  beql      $v0, $s4, .L8004DD60
/* 29140 8004DD40 26100001 */   addiu    $s0, $s0, 1
/* 29144 8004DD44 0220202D */  daddu     $a0, $s1, $zero
/* 29148 8004DD48 A22200D4 */  sb        $v0, 0xd4($s1)
/* 2914C 8004DD4C 90620224 */  lbu       $v0, 0x224($v1)
/* 29150 8004DD50 0240282D */  daddu     $a1, $s2, $zero
/* 29154 8004DD54 0C013E7A */  jal       func_8004F9E8
/* 29158 8004DD58 A22200D5 */   sb       $v0, 0xd5($s1)
/* 2915C 8004DD5C 26100001 */  addiu     $s0, $s0, 1
.L8004DD60:
/* 29160 8004DD60 2A020004 */  slti      $v0, $s0, 4
/* 29164 8004DD64 1440FFF4 */  bnez      $v0, .L8004DD38
/* 29168 8004DD68 02301821 */   addu     $v1, $s1, $s0
/* 2916C 8004DD6C 8E650084 */  lw        $a1, 0x84($s3)
/* 29170 8004DD70 8E660088 */  lw        $a2, 0x88($s3)
/* 29174 8004DD74 8E67008C */  lw        $a3, 0x8c($s3)
/* 29178 8004DD78 0C014D89 */  jal       func_80053624
/* 2917C 8004DD7C 2624002C */   addiu    $a0, $s1, 0x2c
/* 29180 8004DD80 AE600080 */  sw        $zero, 0x80($s3)
.L8004DD84:
/* 29184 8004DD84 8FBF0024 */  lw        $ra, 0x24($sp)
/* 29188 8004DD88 8FB40020 */  lw        $s4, 0x20($sp)
/* 2918C 8004DD8C 8FB3001C */  lw        $s3, 0x1c($sp)
/* 29190 8004DD90 8FB20018 */  lw        $s2, 0x18($sp)
/* 29194 8004DD94 8FB10014 */  lw        $s1, 0x14($sp)
/* 29198 8004DD98 8FB00010 */  lw        $s0, 0x10($sp)
/* 2919C 8004DD9C 03E00008 */  jr        $ra
/* 291A0 8004DDA0 27BD0028 */   addiu    $sp, $sp, 0x28
