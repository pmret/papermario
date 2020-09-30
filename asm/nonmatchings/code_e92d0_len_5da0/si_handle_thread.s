.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel si_handle_thread
/* EB628 802C6C78 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EB62C 802C6C7C AFB00010 */  sw        $s0, 0x10($sp)
/* EB630 802C6C80 0080802D */  daddu     $s0, $a0, $zero
/* EB634 802C6C84 AFBF0014 */  sw        $ra, 0x14($sp)
/* EB638 802C6C88 8E040008 */  lw        $a0, 8($s0)
/* EB63C 802C6C8C 24060057 */  addiu     $a2, $zero, 0x57
/* EB640 802C6C90 0080282D */  daddu     $a1, $a0, $zero
.L802C6C94:
/* EB644 802C6C94 8CA30000 */  lw        $v1, ($a1)
/* EB648 802C6C98 24A50004 */  addiu     $a1, $a1, 4
/* EB64C 802C6C9C 8CA20000 */  lw        $v0, ($a1)
/* EB650 802C6CA0 24A50004 */  addiu     $a1, $a1, 4
/* EB654 802C6CA4 00021080 */  sll       $v0, $v0, 2
/* EB658 802C6CA8 1466FFFA */  bne       $v1, $a2, .L802C6C94
/* EB65C 802C6CAC 00A22821 */   addu     $a1, $a1, $v0
/* EB660 802C6CB0 AE050008 */  sw        $a1, 8($s0)
/* EB664 802C6CB4 92050003 */  lbu       $a1, 3($s0)
/* EB668 802C6CB8 92070004 */  lbu       $a3, 4($s0)
/* EB66C 802C6CBC 0C0B0D74 */  jal       start_script_in_group
/* EB670 802C6CC0 24060060 */   addiu    $a2, $zero, 0x60
/* EB674 802C6CC4 8E030148 */  lw        $v1, 0x148($s0)
/* EB678 802C6CC8 0040302D */  daddu     $a2, $v0, $zero
/* EB67C 802C6CCC ACC30148 */  sw        $v1, 0x148($a2)
/* EB680 802C6CD0 8E02014C */  lw        $v0, 0x14c($s0)
/* EB684 802C6CD4 0000282D */  daddu     $a1, $zero, $zero
/* EB688 802C6CD8 ACC2014C */  sw        $v0, 0x14c($a2)
/* EB68C 802C6CDC 8E02013C */  lw        $v0, 0x13c($s0)
/* EB690 802C6CE0 0200202D */  daddu     $a0, $s0, $zero
/* EB694 802C6CE4 ACC2013C */  sw        $v0, 0x13c($a2)
/* EB698 802C6CE8 8E020140 */  lw        $v0, 0x140($s0)
/* EB69C 802C6CEC 00C0182D */  daddu     $v1, $a2, $zero
/* EB6A0 802C6CF0 ACC20140 */  sw        $v0, 0x140($a2)
.L802C6CF4:
/* EB6A4 802C6CF4 8C820084 */  lw        $v0, 0x84($a0)
/* EB6A8 802C6CF8 24840004 */  addiu     $a0, $a0, 4
/* EB6AC 802C6CFC 24A50001 */  addiu     $a1, $a1, 1
/* EB6B0 802C6D00 AC620084 */  sw        $v0, 0x84($v1)
/* EB6B4 802C6D04 28A20010 */  slti      $v0, $a1, 0x10
/* EB6B8 802C6D08 1440FFFA */  bnez      $v0, .L802C6CF4
/* EB6BC 802C6D0C 24630004 */   addiu    $v1, $v1, 4
/* EB6C0 802C6D10 0000282D */  daddu     $a1, $zero, $zero
/* EB6C4 802C6D14 0200202D */  daddu     $a0, $s0, $zero
/* EB6C8 802C6D18 00C0182D */  daddu     $v1, $a2, $zero
.L802C6D1C:
/* EB6CC 802C6D1C 8C8200C4 */  lw        $v0, 0xc4($a0)
/* EB6D0 802C6D20 24840004 */  addiu     $a0, $a0, 4
/* EB6D4 802C6D24 24A50001 */  addiu     $a1, $a1, 1
/* EB6D8 802C6D28 AC6200C4 */  sw        $v0, 0xc4($v1)
/* EB6DC 802C6D2C 28A20003 */  slti      $v0, $a1, 3
/* EB6E0 802C6D30 1440FFFA */  bnez      $v0, .L802C6D1C
/* EB6E4 802C6D34 24630004 */   addiu    $v1, $v1, 4
/* EB6E8 802C6D38 8FBF0014 */  lw        $ra, 0x14($sp)
/* EB6EC 802C6D3C 8FB00010 */  lw        $s0, 0x10($sp)
/* EB6F0 802C6D40 24020002 */  addiu     $v0, $zero, 2
/* EB6F4 802C6D44 03E00008 */  jr        $ra
/* EB6F8 802C6D48 27BD0018 */   addiu    $sp, $sp, 0x18
