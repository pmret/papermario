.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024367C_C7A35C
/* C7A35C 8024367C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C7A360 80243680 AFBF0010 */  sw        $ra, 0x10($sp)
/* C7A364 80243684 8C82000C */  lw        $v0, 0xc($a0)
/* C7A368 80243688 0C0B1EAF */  jal       evt_get_variable
/* C7A36C 8024368C 8C450000 */   lw       $a1, ($v0)
/* C7A370 80243690 0040182D */  daddu     $v1, $v0, $zero
/* C7A374 80243694 10600012 */  beqz      $v1, .L802436E0
/* C7A378 80243698 0000202D */   daddu    $a0, $zero, $zero
/* C7A37C 8024369C 8C620000 */  lw        $v0, ($v1)
/* C7A380 802436A0 5040000A */  beql      $v0, $zero, .L802436CC
/* C7A384 802436A4 00041080 */   sll      $v0, $a0, 2
/* C7A388 802436A8 3C058024 */  lui       $a1, %hi(D_802474A0)
/* C7A38C 802436AC 24A574A0 */  addiu     $a1, $a1, %lo(D_802474A0)
.L802436B0:
/* C7A390 802436B0 24630004 */  addiu     $v1, $v1, 4
/* C7A394 802436B4 24840001 */  addiu     $a0, $a0, 1
/* C7A398 802436B8 ACA20000 */  sw        $v0, ($a1)
/* C7A39C 802436BC 8C620000 */  lw        $v0, ($v1)
/* C7A3A0 802436C0 1440FFFB */  bnez      $v0, .L802436B0
/* C7A3A4 802436C4 24A50004 */   addiu    $a1, $a1, 4
/* C7A3A8 802436C8 00041080 */  sll       $v0, $a0, 2
.L802436CC:
/* C7A3AC 802436CC 3C018024 */  lui       $at, %hi(D_802474A0)
/* C7A3B0 802436D0 00220821 */  addu      $at, $at, $v0
/* C7A3B4 802436D4 AC2074A0 */  sw        $zero, %lo(D_802474A0)($at)
/* C7A3B8 802436D8 08090DC2 */  j         .L80243708
/* C7A3BC 802436DC 00000000 */   nop
.L802436E0:
/* C7A3C0 802436E0 3C038024 */  lui       $v1, %hi(D_802474A0)
/* C7A3C4 802436E4 246374A0 */  addiu     $v1, $v1, %lo(D_802474A0)
/* C7A3C8 802436E8 0060282D */  daddu     $a1, $v1, $zero
.L802436EC:
/* C7A3CC 802436EC 24820010 */  addiu     $v0, $a0, 0x10
/* C7A3D0 802436F0 AC620000 */  sw        $v0, ($v1)
/* C7A3D4 802436F4 24630004 */  addiu     $v1, $v1, 4
/* C7A3D8 802436F8 24840001 */  addiu     $a0, $a0, 1
/* C7A3DC 802436FC 28820070 */  slti      $v0, $a0, 0x70
/* C7A3E0 80243700 1440FFFA */  bnez      $v0, .L802436EC
/* C7A3E4 80243704 ACA001C0 */   sw       $zero, 0x1c0($a1)
.L80243708:
/* C7A3E8 80243708 8FBF0010 */  lw        $ra, 0x10($sp)
/* C7A3EC 8024370C 24020002 */  addiu     $v0, $zero, 2
/* C7A3F0 80243710 03E00008 */  jr        $ra
/* C7A3F4 80243714 27BD0018 */   addiu    $sp, $sp, 0x18
