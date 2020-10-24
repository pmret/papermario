.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802432C0_96C480
/* 96C480 802432C0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 96C484 802432C4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 96C488 802432C8 10A00003 */  beqz      $a1, .L802432D8
/* 96C48C 802432CC 8C86000C */   lw       $a2, 0xc($a0)
/* 96C490 802432D0 3C018025 */  lui       $at, 0x8025
/* 96C494 802432D4 AC208780 */  sw        $zero, -0x7880($at)
.L802432D8:
/* 96C498 802432D8 3C038025 */  lui       $v1, 0x8025
/* 96C49C 802432DC 24638780 */  addiu     $v1, $v1, -0x7880
/* 96C4A0 802432E0 8C620000 */  lw        $v0, ($v1)
/* 96C4A4 802432E4 54400003 */  bnel      $v0, $zero, .L802432F4
/* 96C4A8 802432E8 AC600000 */   sw       $zero, ($v1)
/* 96C4AC 802432EC 08090CC2 */  j         .L80243308
/* 96C4B0 802432F0 0000102D */   daddu    $v0, $zero, $zero
.L802432F4:
/* 96C4B4 802432F4 8CC50000 */  lw        $a1, ($a2)
/* 96C4B8 802432F8 3C068025 */  lui       $a2, 0x8025
/* 96C4BC 802432FC 0C0B2026 */  jal       set_variable
/* 96C4C0 80243300 8CC68784 */   lw       $a2, -0x787c($a2)
/* 96C4C4 80243304 24020002 */  addiu     $v0, $zero, 2
.L80243308:
/* 96C4C8 80243308 8FBF0010 */  lw        $ra, 0x10($sp)
/* 96C4CC 8024330C 03E00008 */  jr        $ra
/* 96C4D0 80243310 27BD0018 */   addiu    $sp, $sp, 0x18
