.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A78_890618
/* 890618 80240A78 8C820084 */  lw        $v0, 0x84($a0)
/* 89061C 80240A7C 3C038024 */  lui       $v1, 0x8024
/* 890620 80240A80 246327BC */  addiu     $v1, $v1, 0x27bc
/* 890624 80240A84 000210C0 */  sll       $v0, $v0, 3
/* 890628 80240A88 00431021 */  addu      $v0, $v0, $v1
/* 89062C 80240A8C 8C430000 */  lw        $v1, ($v0)
/* 890630 80240A90 AC8300AC */  sw        $v1, 0xac($a0)
/* 890634 80240A94 8C420004 */  lw        $v0, 4($v0)
/* 890638 80240A98 AC8200B0 */  sw        $v0, 0xb0($a0)
/* 89063C 80240A9C 03E00008 */  jr        $ra
/* 890640 80240AA0 24020002 */   addiu    $v0, $zero, 2
