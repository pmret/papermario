.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241680_BE0410
/* BE0410 80241680 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BE0414 80241684 AFBF0010 */  sw        $ra, 0x10($sp)
/* BE0418 80241688 8C82000C */  lw        $v0, 0xc($a0)
/* BE041C 8024168C 0C0B1EAF */  jal       get_variable
/* BE0420 80241690 8C450000 */   lw       $a1, ($v0)
/* BE0424 80241694 0040182D */  daddu     $v1, $v0, $zero
/* BE0428 80241698 10600012 */  beqz      $v1, .L802416E4
/* BE042C 8024169C 0000202D */   daddu    $a0, $zero, $zero
/* BE0430 802416A0 8C620000 */  lw        $v0, ($v1)
/* BE0434 802416A4 5040000A */  beql      $v0, $zero, .L802416D0
/* BE0438 802416A8 00041080 */   sll      $v0, $a0, 2
/* BE043C 802416AC 3C058024 */  lui       $a1, %hi(D_80244A20)
/* BE0440 802416B0 24A54A20 */  addiu     $a1, $a1, %lo(D_80244A20)
.L802416B4:
/* BE0444 802416B4 24630004 */  addiu     $v1, $v1, 4
/* BE0448 802416B8 24840001 */  addiu     $a0, $a0, 1
/* BE044C 802416BC ACA20000 */  sw        $v0, ($a1)
/* BE0450 802416C0 8C620000 */  lw        $v0, ($v1)
/* BE0454 802416C4 1440FFFB */  bnez      $v0, .L802416B4
/* BE0458 802416C8 24A50004 */   addiu    $a1, $a1, 4
/* BE045C 802416CC 00041080 */  sll       $v0, $a0, 2
.L802416D0:
/* BE0460 802416D0 3C018024 */  lui       $at, %hi(D_80244A20)
/* BE0464 802416D4 00220821 */  addu      $at, $at, $v0
/* BE0468 802416D8 AC204A20 */  sw        $zero, %lo(D_80244A20)($at)
/* BE046C 802416DC 080905C3 */  j         .L8024170C
/* BE0470 802416E0 00000000 */   nop      
.L802416E4:
/* BE0474 802416E4 3C038024 */  lui       $v1, %hi(D_80244A20)
/* BE0478 802416E8 24634A20 */  addiu     $v1, $v1, %lo(D_80244A20)
/* BE047C 802416EC 0060282D */  daddu     $a1, $v1, $zero
.L802416F0:
/* BE0480 802416F0 24820010 */  addiu     $v0, $a0, 0x10
/* BE0484 802416F4 AC620000 */  sw        $v0, ($v1)
/* BE0488 802416F8 24630004 */  addiu     $v1, $v1, 4
/* BE048C 802416FC 24840001 */  addiu     $a0, $a0, 1
/* BE0490 80241700 28820070 */  slti      $v0, $a0, 0x70
/* BE0494 80241704 1440FFFA */  bnez      $v0, .L802416F0
/* BE0498 80241708 ACA001C0 */   sw       $zero, 0x1c0($a1)
.L8024170C:
/* BE049C 8024170C 8FBF0010 */  lw        $ra, 0x10($sp)
/* BE04A0 80241710 24020002 */  addiu     $v0, $zero, 2
/* BE04A4 80241714 03E00008 */  jr        $ra
/* BE04A8 80241718 27BD0018 */   addiu    $sp, $sp, 0x18
/* BE04AC 8024171C 00000000 */  nop       
