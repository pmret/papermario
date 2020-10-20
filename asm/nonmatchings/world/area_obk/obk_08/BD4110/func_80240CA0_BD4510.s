.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240CA0_BD4510
/* BD4510 80240CA0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BD4514 80240CA4 AFB10014 */  sw        $s1, 0x14($sp)
/* BD4518 80240CA8 0080882D */  daddu     $s1, $a0, $zero
/* BD451C 80240CAC AFBF0018 */  sw        $ra, 0x18($sp)
/* BD4520 80240CB0 AFB00010 */  sw        $s0, 0x10($sp)
/* BD4524 80240CB4 0C00EABB */  jal       get_npc_unsafe
/* BD4528 80240CB8 8E24014C */   lw       $a0, 0x14c($s1)
/* BD452C 80240CBC 0000202D */  daddu     $a0, $zero, $zero
/* BD4530 80240CC0 0C00EABB */  jal       get_npc_unsafe
/* BD4534 80240CC4 0040802D */   daddu    $s0, $v0, $zero
/* BD4538 80240CC8 AE020020 */  sw        $v0, 0x20($s0)
/* BD453C 80240CCC 8E23014C */  lw        $v1, 0x14c($s1)
/* BD4540 80240CD0 00032040 */  sll       $a0, $v1, 1
/* BD4544 80240CD4 00832021 */  addu      $a0, $a0, $v1
/* BD4548 80240CD8 00041900 */  sll       $v1, $a0, 4
/* BD454C 80240CDC 00641823 */  subu      $v1, $v1, $a0
/* BD4550 80240CE0 AE230078 */  sw        $v1, 0x78($s1)
/* BD4554 80240CE4 8E030000 */  lw        $v1, ($s0)
/* BD4558 80240CE8 3C040004 */  lui       $a0, 4
/* BD455C 80240CEC 00641825 */  or        $v1, $v1, $a0
/* BD4560 80240CF0 AE030000 */  sw        $v1, ($s0)
/* BD4564 80240CF4 AE200074 */  sw        $zero, 0x74($s1)
/* BD4568 80240CF8 8FBF0018 */  lw        $ra, 0x18($sp)
/* BD456C 80240CFC 8FB10014 */  lw        $s1, 0x14($sp)
/* BD4570 80240D00 8FB00010 */  lw        $s0, 0x10($sp)
/* BD4574 80240D04 24020002 */  addiu     $v0, $zero, 2
/* BD4578 80240D08 03E00008 */  jr        $ra
/* BD457C 80240D0C 27BD0020 */   addiu    $sp, $sp, 0x20
