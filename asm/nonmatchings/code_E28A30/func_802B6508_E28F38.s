.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802B6508_E28F38
/* E28F38 802B6508 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* E28F3C 802B650C AFB00018 */  sw        $s0, 0x18($sp)
/* E28F40 802B6510 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* E28F44 802B6514 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* E28F48 802B6518 AFBF001C */  sw        $ra, 0x1c($sp)
/* E28F4C 802B651C 8E030000 */  lw        $v1, ($s0)
/* E28F50 802B6520 04610030 */  bgez      $v1, .L802B65E4
/* E28F54 802B6524 3C027FFF */   lui      $v0, 0x7fff
/* E28F58 802B6528 3442FFFF */  ori       $v0, $v0, 0xffff
/* E28F5C 802B652C 27A40010 */  addiu     $a0, $sp, 0x10
/* E28F60 802B6530 00621024 */  and       $v0, $v1, $v0
/* E28F64 802B6534 AE020000 */  sw        $v0, ($s0)
/* E28F68 802B6538 24020005 */  addiu     $v0, $zero, 5
/* E28F6C 802B653C 27A50014 */  addiu     $a1, $sp, 0x14
/* E28F70 802B6540 AE000054 */  sw        $zero, 0x54($s0)
/* E28F74 802B6544 AE000060 */  sw        $zero, 0x60($s0)
/* E28F78 802B6548 0C0388C1 */  jal       input_to_move_vector
/* E28F7C 802B654C A6020008 */   sh       $v0, 8($s0)
/* E28F80 802B6550 C7A20010 */  lwc1      $f2, 0x10($sp)
/* E28F84 802B6554 3C014234 */  lui       $at, 0x4234
/* E28F88 802B6558 44810000 */  mtc1      $at, $f0
/* E28F8C 802B655C 00000000 */  nop
/* E28F90 802B6560 4602003E */  c.le.s    $f0, $f2
/* E28F94 802B6564 00000000 */  nop
/* E28F98 802B6568 45000008 */  bc1f      .L802B658C
/* E28F9C 802B656C 00000000 */   nop
/* E28FA0 802B6570 3C014307 */  lui       $at, 0x4307
/* E28FA4 802B6574 44810000 */  mtc1      $at, $f0
/* E28FA8 802B6578 00000000 */  nop
/* E28FAC 802B657C 4600103E */  c.le.s    $f2, $f0
/* E28FB0 802B6580 00000000 */  nop
/* E28FB4 802B6584 45010011 */  bc1t      .L802B65CC
/* E28FB8 802B6588 3C040008 */   lui      $a0, 8
.L802B658C:
/* E28FBC 802B658C 3C014361 */  lui       $at, 0x4361
/* E28FC0 802B6590 44810000 */  mtc1      $at, $f0
/* E28FC4 802B6594 00000000 */  nop
/* E28FC8 802B6598 4602003E */  c.le.s    $f0, $f2
/* E28FCC 802B659C 00000000 */  nop
/* E28FD0 802B65A0 4500000E */  bc1f      .L802B65DC
/* E28FD4 802B65A4 3C040006 */   lui      $a0, 6
/* E28FD8 802B65A8 3C01439D */  lui       $at, 0x439d
/* E28FDC 802B65AC 34218000 */  ori       $at, $at, 0x8000
/* E28FE0 802B65B0 44810000 */  mtc1      $at, $f0
/* E28FE4 802B65B4 00000000 */  nop
/* E28FE8 802B65B8 4600103E */  c.le.s    $f2, $f0
/* E28FEC 802B65BC 00000000 */  nop
/* E28FF0 802B65C0 45000006 */  bc1f      .L802B65DC
/* E28FF4 802B65C4 00000000 */   nop
/* E28FF8 802B65C8 3C040008 */  lui       $a0, 8
.L802B65CC:
/* E28FFC 802B65CC 0C037FDE */  jal       func_800DFF78
/* E29000 802B65D0 34840020 */   ori      $a0, $a0, 0x20
/* E29004 802B65D4 080AD979 */  j         .L802B65E4
/* E29008 802B65D8 00000000 */   nop
.L802B65DC:
/* E2900C 802B65DC 0C037FBF */  jal       func_800DFEFC
/* E29010 802B65E0 34840004 */   ori      $a0, $a0, 4
.L802B65E4:
/* E29014 802B65E4 0C039858 */  jal       check_input_jump
/* E29018 802B65E8 00000000 */   nop
/* E2901C 802B65EC 8E020004 */  lw        $v0, 4($s0)
/* E29020 802B65F0 3C030080 */  lui       $v1, 0x80
/* E29024 802B65F4 00431024 */  and       $v0, $v0, $v1
/* E29028 802B65F8 1040000B */  beqz      $v0, .L802B6628
/* E2902C 802B65FC 00000000 */   nop
/* E29030 802B6600 86020008 */  lh        $v0, 8($s0)
/* E29034 802B6604 96030008 */  lhu       $v1, 8($s0)
/* E29038 802B6608 10400007 */  beqz      $v0, .L802B6628
/* E2903C 802B660C 2462FFFF */   addiu    $v0, $v1, -1
/* E29040 802B6610 A6020008 */  sh        $v0, 8($s0)
/* E29044 802B6614 00021400 */  sll       $v0, $v0, 0x10
/* E29048 802B6618 14400003 */  bnez      $v0, .L802B6628
/* E2904C 802B661C 00000000 */   nop
/* E29050 802B6620 0C039769 */  jal       set_action_state
/* E29054 802B6624 0000202D */   daddu    $a0, $zero, $zero
.L802B6628:
/* E29058 802B6628 8FBF001C */  lw        $ra, 0x1c($sp)
/* E2905C 802B662C 8FB00018 */  lw        $s0, 0x18($sp)
/* E29060 802B6630 03E00008 */  jr        $ra
/* E29064 802B6634 27BD0020 */   addiu    $sp, $sp, 0x20
