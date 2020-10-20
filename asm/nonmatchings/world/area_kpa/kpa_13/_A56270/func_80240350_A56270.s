.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240350_A56270
/* A56270 80240350 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A56274 80240354 AFBF0010 */  sw        $ra, 0x10($sp)
/* A56278 80240358 8C82000C */  lw        $v0, 0xc($a0)
/* A5627C 8024035C 3C068016 */  lui       $a2, 0x8016
/* A56280 80240360 84C6A556 */  lh        $a2, -0x5aaa($a2)
/* A56284 80240364 0C0B2026 */  jal       set_variable
/* A56288 80240368 8C450000 */   lw       $a1, ($v0)
/* A5628C 8024036C 8FBF0010 */  lw        $ra, 0x10($sp)
/* A56290 80240370 24020002 */  addiu     $v0, $zero, 2
/* A56294 80240374 03E00008 */  jr        $ra
/* A56298 80240378 27BD0018 */   addiu    $sp, $sp, 0x18
