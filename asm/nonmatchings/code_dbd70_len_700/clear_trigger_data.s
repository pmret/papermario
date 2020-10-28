.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel clear_trigger_data
/* DBD80 80145680 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* DBD84 80145684 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* DBD88 80145688 80420070 */  lb        $v0, 0x70($v0)
/* DBD8C 8014568C 3C048016 */  lui       $a0, %hi(gCollisionStatus)
/* DBD90 80145690 2484A550 */  addiu     $a0, $a0, %lo(gCollisionStatus)
/* DBD94 80145694 14400005 */  bnez      $v0, .L801456AC
/* DBD98 80145698 00000000 */   nop      
/* DBD9C 8014569C 3C028016 */  lui       $v0, %hi(gTriggerList1)
/* DBDA0 801456A0 24429190 */  addiu     $v0, $v0, %lo(gTriggerList1)
/* DBDA4 801456A4 080515AD */  j         .L801456B4
/* DBDA8 801456A8 00000000 */   nop      
.L801456AC:
/* DBDAC 801456AC 3C028016 */  lui       $v0, %hi(gTriggerList2)
/* DBDB0 801456B0 24429290 */  addiu     $v0, $v0, %lo(gTriggerList2)
.L801456B4:
/* DBDB4 801456B4 3C018016 */  lui       $at, %hi(gCurrentTriggerListPtr)
/* DBDB8 801456B8 AC229390 */  sw        $v0, %lo(gCurrentTriggerListPtr)($at)
/* DBDBC 801456BC 3C028016 */  lui       $v0, %hi(gCurrentTriggerListPtr)
/* DBDC0 801456C0 8C429390 */  lw        $v0, %lo(gCurrentTriggerListPtr)($v0)
/* DBDC4 801456C4 2403003F */  addiu     $v1, $zero, 0x3f
/* DBDC8 801456C8 244200FC */  addiu     $v0, $v0, 0xfc
.L801456CC:
/* DBDCC 801456CC AC400000 */  sw        $zero, ($v0)
/* DBDD0 801456D0 2463FFFF */  addiu     $v1, $v1, -1
/* DBDD4 801456D4 0461FFFD */  bgez      $v1, .L801456CC
/* DBDD8 801456D8 2442FFFC */   addiu    $v0, $v0, -4
/* DBDDC 801456DC 2402FFFF */  addiu     $v0, $zero, -1
/* DBDE0 801456E0 3C018015 */  lui       $at, %hi(gTriggerCount)
/* DBDE4 801456E4 A4201334 */  sh        $zero, %lo(gTriggerCount)($at)
/* DBDE8 801456E8 A4820000 */  sh        $v0, ($a0)
/* DBDEC 801456EC A4820002 */  sh        $v0, 2($a0)
/* DBDF0 801456F0 A4820004 */  sh        $v0, 4($a0)
/* DBDF4 801456F4 A4820008 */  sh        $v0, 8($a0)
/* DBDF8 801456F8 A482000A */  sh        $v0, 0xa($a0)
/* DBDFC 801456FC A482000C */  sh        $v0, 0xc($a0)
/* DBE00 80145700 A482000E */  sh        $v0, 0xe($a0)
/* DBE04 80145704 A4820010 */  sh        $v0, 0x10($a0)
/* DBE08 80145708 A4820012 */  sh        $v0, 0x12($a0)
/* DBE0C 8014570C A4820014 */  sh        $v0, 0x14($a0)
/* DBE10 80145710 A4800016 */  sh        $zero, 0x16($a0)
/* DBE14 80145714 A4820018 */  sh        $v0, 0x18($a0)
/* DBE18 80145718 AC80001C */  sw        $zero, 0x1c($a0)
/* DBE1C 8014571C AC800020 */  sw        $zero, 0x20($a0)
/* DBE20 80145720 03E00008 */  jr        $ra
/* DBE24 80145724 AC800024 */   sw       $zero, 0x24($a0)
