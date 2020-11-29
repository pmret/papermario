.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405C8_CF8138
/* CF8138 802405C8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CF813C 802405CC AFBF0010 */  sw        $ra, 0x10($sp)
/* CF8140 802405D0 8C82000C */  lw        $v0, 0xc($a0)
/* CF8144 802405D4 0C0B1EAF */  jal       get_variable
/* CF8148 802405D8 8C450000 */   lw       $a1, ($v0)
/* CF814C 802405DC 0040182D */  daddu     $v1, $v0, $zero
/* CF8150 802405E0 10600012 */  beqz      $v1, .L8024062C
/* CF8154 802405E4 0000202D */   daddu    $a0, $zero, $zero
/* CF8158 802405E8 8C620000 */  lw        $v0, ($v1)
/* CF815C 802405EC 5040000A */  beql      $v0, $zero, .L80240618
/* CF8160 802405F0 00041080 */   sll      $v0, $a0, 2
/* CF8164 802405F4 3C058025 */  lui       $a1, %hi(D_8024DBC0)
/* CF8168 802405F8 24A5DBC0 */  addiu     $a1, $a1, %lo(D_8024DBC0)
.L802405FC:
/* CF816C 802405FC 24630004 */  addiu     $v1, $v1, 4
/* CF8170 80240600 24840001 */  addiu     $a0, $a0, 1
/* CF8174 80240604 ACA20000 */  sw        $v0, ($a1)
/* CF8178 80240608 8C620000 */  lw        $v0, ($v1)
/* CF817C 8024060C 1440FFFB */  bnez      $v0, .L802405FC
/* CF8180 80240610 24A50004 */   addiu    $a1, $a1, 4
/* CF8184 80240614 00041080 */  sll       $v0, $a0, 2
.L80240618:
/* CF8188 80240618 3C018025 */  lui       $at, %hi(D_8024DBC0)
/* CF818C 8024061C 00220821 */  addu      $at, $at, $v0
/* CF8190 80240620 AC20DBC0 */  sw        $zero, %lo(D_8024DBC0)($at)
/* CF8194 80240624 08090195 */  j         .L80240654
/* CF8198 80240628 00000000 */   nop      
.L8024062C:
/* CF819C 8024062C 3C038025 */  lui       $v1, %hi(D_8024DBC0)
/* CF81A0 80240630 2463DBC0 */  addiu     $v1, $v1, %lo(D_8024DBC0)
/* CF81A4 80240634 0060282D */  daddu     $a1, $v1, $zero
.L80240638:
/* CF81A8 80240638 24820010 */  addiu     $v0, $a0, 0x10
/* CF81AC 8024063C AC620000 */  sw        $v0, ($v1)
/* CF81B0 80240640 24630004 */  addiu     $v1, $v1, 4
/* CF81B4 80240644 24840001 */  addiu     $a0, $a0, 1
/* CF81B8 80240648 28820070 */  slti      $v0, $a0, 0x70
/* CF81BC 8024064C 1440FFFA */  bnez      $v0, .L80240638
/* CF81C0 80240650 ACA001C0 */   sw       $zero, 0x1c0($a1)
.L80240654:
/* CF81C4 80240654 8FBF0010 */  lw        $ra, 0x10($sp)
/* CF81C8 80240658 24020002 */  addiu     $v0, $zero, 2
/* CF81CC 8024065C 03E00008 */  jr        $ra
/* CF81D0 80240660 27BD0018 */   addiu    $sp, $sp, 0x18
