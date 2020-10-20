.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242510
/* E07870 80242510 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E07874 80242514 AFB00010 */  sw        $s0, 0x10($sp)
/* E07878 80242518 3C108025 */  lui       $s0, 0x8025
/* E0787C 8024251C 26109440 */  addiu     $s0, $s0, -0x6bc0
/* E07880 80242520 3C058024 */  lui       $a1, 0x8024
/* E07884 80242524 24A521E8 */  addiu     $a1, $a1, 0x21e8
/* E07888 80242528 AFBF0014 */  sw        $ra, 0x14($sp)
/* E0788C 8024252C 3C018025 */  lui       $at, 0x8025
/* E07890 80242530 AC30A2C4 */  sw        $s0, -0x5d3c($at)
/* E07894 80242534 0C048C8F */  jal       bind_dynamic_entity_7
/* E07898 80242538 0000202D */   daddu    $a0, $zero, $zero
/* E0789C 8024253C 2404001F */  addiu     $a0, $zero, 0x1f
/* E078A0 80242540 26030E0C */  addiu     $v1, $s0, 0xe0c
/* E078A4 80242544 AE020000 */  sw        $v0, ($s0)
.L80242548:
/* E078A8 80242548 A4600074 */  sh        $zero, 0x74($v1)
/* E078AC 8024254C 2484FFFF */  addiu     $a0, $a0, -1
/* E078B0 80242550 0481FFFD */  bgez      $a0, .L80242548
/* E078B4 80242554 2463FF8C */   addiu    $v1, $v1, -0x74
/* E078B8 80242558 8FBF0014 */  lw        $ra, 0x14($sp)
/* E078BC 8024255C 8FB00010 */  lw        $s0, 0x10($sp)
/* E078C0 80242560 03E00008 */  jr        $ra
/* E078C4 80242564 27BD0018 */   addiu    $sp, $sp, 0x18
