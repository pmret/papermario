.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241524_A94C64
/* A94C64 80241524 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A94C68 80241528 3C05FE36 */  lui       $a1, 0xfe36
/* A94C6C 8024152C AFBF0010 */  sw        $ra, 0x10($sp)
/* A94C70 80241530 8C820148 */  lw        $v0, 0x148($a0)
/* A94C74 80241534 3C06800B */  lui       $a2, %hi(gCurrentEncounter+0x8C)
/* A94C78 80241538 8CC60F9C */  lw        $a2, %lo(gCurrentEncounter+0x8C)($a2)
/* A94C7C 8024153C 34A53C80 */  ori       $a1, $a1, 0x3c80
/* A94C80 80241540 00C23026 */  xor       $a2, $a2, $v0
/* A94C84 80241544 0C0B2026 */  jal       set_variable
/* A94C88 80241548 2CC60001 */   sltiu    $a2, $a2, 1
/* A94C8C 8024154C 8FBF0010 */  lw        $ra, 0x10($sp)
/* A94C90 80241550 24020002 */  addiu     $v0, $zero, 2
/* A94C94 80241554 03E00008 */  jr        $ra
/* A94C98 80241558 27BD0018 */   addiu    $sp, $sp, 0x18
