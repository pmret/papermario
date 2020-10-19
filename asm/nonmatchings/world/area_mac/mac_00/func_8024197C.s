.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024197C
/* 7EC68C 8024197C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7EC690 80241980 AFBF0010 */  sw        $ra, 0x10($sp)
/* 7EC694 80241984 8C82000C */  lw        $v0, 0xc($a0)
/* 7EC698 80241988 0C0B1EAF */  jal       get_variable
/* 7EC69C 8024198C 8C450000 */   lw       $a1, ($v0)
/* 7EC6A0 80241990 0040182D */  daddu     $v1, $v0, $zero
/* 7EC6A4 80241994 10600012 */  beqz      $v1, .L802419E0
/* 7EC6A8 80241998 0000202D */   daddu    $a0, $zero, $zero
/* 7EC6AC 8024199C 8C620000 */  lw        $v0, ($v1)
/* 7EC6B0 802419A0 5040000A */  beql      $v0, $zero, .L802419CC
/* 7EC6B4 802419A4 00041080 */   sll      $v0, $a0, 2
/* 7EC6B8 802419A8 3C058025 */  lui       $a1, 0x8025
/* 7EC6BC 802419AC 24A55BA0 */  addiu     $a1, $a1, 0x5ba0
.L802419B0:
/* 7EC6C0 802419B0 24630004 */  addiu     $v1, $v1, 4
/* 7EC6C4 802419B4 24840001 */  addiu     $a0, $a0, 1
/* 7EC6C8 802419B8 ACA20000 */  sw        $v0, ($a1)
/* 7EC6CC 802419BC 8C620000 */  lw        $v0, ($v1)
/* 7EC6D0 802419C0 1440FFFB */  bnez      $v0, .L802419B0
/* 7EC6D4 802419C4 24A50004 */   addiu    $a1, $a1, 4
/* 7EC6D8 802419C8 00041080 */  sll       $v0, $a0, 2
.L802419CC:
/* 7EC6DC 802419CC 3C018025 */  lui       $at, 0x8025
/* 7EC6E0 802419D0 00220821 */  addu      $at, $at, $v0
/* 7EC6E4 802419D4 AC205BA0 */  sw        $zero, 0x5ba0($at)
/* 7EC6E8 802419D8 08090682 */  j         .L80241A08
/* 7EC6EC 802419DC 00000000 */   nop      
.L802419E0:
/* 7EC6F0 802419E0 3C038025 */  lui       $v1, 0x8025
/* 7EC6F4 802419E4 24635BA0 */  addiu     $v1, $v1, 0x5ba0
/* 7EC6F8 802419E8 0060282D */  daddu     $a1, $v1, $zero
.L802419EC:
/* 7EC6FC 802419EC 24820010 */  addiu     $v0, $a0, 0x10
/* 7EC700 802419F0 AC620000 */  sw        $v0, ($v1)
/* 7EC704 802419F4 24630004 */  addiu     $v1, $v1, 4
/* 7EC708 802419F8 24840001 */  addiu     $a0, $a0, 1
/* 7EC70C 802419FC 28820070 */  slti      $v0, $a0, 0x70
/* 7EC710 80241A00 1440FFFA */  bnez      $v0, .L802419EC
/* 7EC714 80241A04 ACA001C0 */   sw       $zero, 0x1c0($a1)
.L80241A08:
/* 7EC718 80241A08 8FBF0010 */  lw        $ra, 0x10($sp)
/* 7EC71C 80241A0C 24020002 */  addiu     $v0, $zero, 2
/* 7EC720 80241A10 03E00008 */  jr        $ra
/* 7EC724 80241A14 27BD0018 */   addiu    $sp, $sp, 0x18
