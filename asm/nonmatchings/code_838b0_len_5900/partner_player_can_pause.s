.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel partner_player_can_pause
/* 84890 800EB3E0 3C028011 */  lui       $v0, %hi(D_8010CFEC)
/* 84894 800EB3E4 8C42CFEC */  lw        $v0, %lo(D_8010CFEC)($v0)
/* 84898 800EB3E8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8489C 800EB3EC 1040000B */  beqz      $v0, .L800EB41C
/* 848A0 800EB3F0 AFBF0010 */   sw       $ra, 0x10($sp)
/* 848A4 800EB3F4 8C420030 */  lw        $v0, 0x30($v0)
/* 848A8 800EB3F8 50400009 */  beql      $v0, $zero, .L800EB420
/* 848AC 800EB3FC 24020001 */   addiu    $v0, $zero, 1
/* 848B0 800EB400 3C048011 */  lui       $a0, %hi(D_8010C930)
/* 848B4 800EB404 8C84C930 */  lw        $a0, %lo(D_8010C930)($a0)
/* 848B8 800EB408 0040F809 */  jalr      $v0
/* 848BC 800EB40C 00000000 */   nop      
/* 848C0 800EB410 0040182D */  daddu     $v1, $v0, $zero
/* 848C4 800EB414 10600002 */  beqz      $v1, .L800EB420
/* 848C8 800EB418 0000102D */   daddu    $v0, $zero, $zero
.L800EB41C:
/* 848CC 800EB41C 24020001 */  addiu     $v0, $zero, 1
.L800EB420:
/* 848D0 800EB420 8FBF0010 */  lw        $ra, 0x10($sp)
/* 848D4 800EB424 03E00008 */  jr        $ra
/* 848D8 800EB428 27BD0018 */   addiu    $sp, $sp, 0x18
