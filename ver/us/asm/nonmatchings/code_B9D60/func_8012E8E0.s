.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8012E8E0
/* C4FE0 8012E8E0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C4FE4 8012E8E4 0080502D */  daddu     $t2, $a0, $zero
/* C4FE8 8012E8E8 00A0482D */  daddu     $t1, $a1, $zero
/* C4FEC 8012E8EC 00C0202D */  daddu     $a0, $a2, $zero
/* C4FF0 8012E8F0 3C02802F */  lui       $v0, %hi(D_802EB5A8)
/* C4FF4 8012E8F4 2442B5A8 */  addiu     $v0, $v0, %lo(D_802EB5A8)
/* C4FF8 8012E8F8 000A2880 */  sll       $a1, $t2, 2
/* C4FFC 8012E8FC 00A22821 */  addu      $a1, $a1, $v0
/* C5000 8012E900 00091040 */  sll       $v0, $t1, 1
/* C5004 8012E904 00491021 */  addu      $v0, $v0, $t1
/* C5008 8012E908 AFBF001C */  sw        $ra, 0x1c($sp)
/* C500C 8012E90C AFB00018 */  sw        $s0, 0x18($sp)
/* C5010 8012E910 8CA60000 */  lw        $a2, ($a1)
/* C5014 8012E914 00021080 */  sll       $v0, $v0, 2
/* C5018 8012E918 8CC30008 */  lw        $v1, 8($a2)
/* C501C 8012E91C 3C08802F */  lui       $t0, %hi(D_802F4560)
/* C5020 8012E920 25084560 */  addiu     $t0, $t0, %lo(D_802F4560)
/* C5024 8012E924 00431021 */  addu      $v0, $v0, $v1
/* C5028 8012E928 94C30004 */  lhu       $v1, 4($a2)
/* C502C 8012E92C 00073900 */  sll       $a3, $a3, 4
/* C5030 8012E930 00640018 */  mult      $v1, $a0
/* C5034 8012E934 8FB00030 */  lw        $s0, 0x30($sp)
/* C5038 8012E938 8C420000 */  lw        $v0, ($v0)
/* C503C 8012E93C 00E83821 */  addu      $a3, $a3, $t0
/* C5040 8012E940 AE070004 */  sw        $a3, 4($s0)
/* C5044 8012E944 00005812 */  mflo      $t3
/* C5048 8012E948 004B1021 */  addu      $v0, $v0, $t3
/* C504C 8012E94C AE020000 */  sw        $v0, ($s0)
/* C5050 8012E950 8CA20000 */  lw        $v0, ($a1)
/* C5054 8012E954 90420000 */  lbu       $v0, ($v0)
/* C5058 8012E958 0120302D */  daddu     $a2, $t1, $zero
/* C505C 8012E95C A2020008 */  sb        $v0, 8($s0)
/* C5060 8012E960 8CA20000 */  lw        $v0, ($a1)
/* C5064 8012E964 3C073F80 */  lui       $a3, 0x3f80
/* C5068 8012E968 90420001 */  lbu       $v0, 1($v0)
/* C506C 8012E96C 0140282D */  daddu     $a1, $t2, $zero
/* C5070 8012E970 A2020009 */  sb        $v0, 9($s0)
/* C5074 8012E974 AFA00010 */  sw        $zero, 0x10($sp)
/* C5078 8012E978 0C04977D */  jal       get_char_width
/* C507C 8012E97C AFA00014 */   sw       $zero, 0x14($sp)
/* C5080 8012E980 92030009 */  lbu       $v1, 9($s0)
/* C5084 8012E984 A202000A */  sb        $v0, 0xa($s0)
/* C5088 8012E988 A203000B */  sb        $v1, 0xb($s0)
/* C508C 8012E98C 8FBF001C */  lw        $ra, 0x1c($sp)
/* C5090 8012E990 8FB00018 */  lw        $s0, 0x18($sp)
/* C5094 8012E994 03E00008 */  jr        $ra
/* C5098 8012E998 27BD0020 */   addiu    $sp, $sp, 0x20
/* C509C 8012E99C 00000000 */  nop
