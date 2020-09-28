.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osViSwapBuffer
/* 42420 80067020 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 42424 80067024 AFB00010 */  sw        $s0, 0x10($sp)
/* 42428 80067028 AFBF0014 */  sw        $ra, 0x14($sp)
/* 4242C 8006702C 0C01ACD8 */  jal       __osDisableInt
/* 42430 80067030 00808021 */   addu     $s0, $a0, $zero
/* 42434 80067034 3C048009 */  lui       $a0, %hi(D_800959D4)
/* 42438 80067038 8C8459D4 */  lw        $a0, %lo(D_800959D4)($a0)
/* 4243C 8006703C 94830000 */  lhu       $v1, ($a0)
/* 42440 80067040 AC900004 */  sw        $s0, 4($a0)
/* 42444 80067044 34630010 */  ori       $v1, $v1, 0x10
/* 42448 80067048 A4830000 */  sh        $v1, ($a0)
/* 4244C 8006704C 0C01ACF4 */  jal       __osRestoreInt
/* 42450 80067050 00402021 */   addu     $a0, $v0, $zero
/* 42454 80067054 8FBF0014 */  lw        $ra, 0x14($sp)
/* 42458 80067058 8FB00010 */  lw        $s0, 0x10($sp)
/* 4245C 8006705C 03E00008 */  jr        $ra
/* 42460 80067060 27BD0018 */   addiu    $sp, $sp, 0x18
/* 42464 80067064 00000000 */  nop       
/* 42468 80067068 00000000 */  nop       
/* 4246C 8006706C 00000000 */  nop       
