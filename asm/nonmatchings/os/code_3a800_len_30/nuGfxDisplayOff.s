.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel nuGfxDisplayOff
/* 3A800 8005F400 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3A804 8005F404 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3A808 8005F408 3C01800A */  lui       $at, 0x800a
/* 3A80C 8005F40C AC20A5F8 */  sw        $zero, -0x5a08($at)
/* 3A810 8005F410 0C019CE0 */  jal       osViBlack
/* 3A814 8005F414 24040001 */   addiu    $a0, $zero, 1
/* 3A818 8005F418 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3A81C 8005F41C 03E00008 */  jr        $ra
/* 3A820 8005F420 27BD0018 */   addiu    $sp, $sp, 0x18
/* 3A824 8005F424 00000000 */  nop       
/* 3A828 8005F428 00000000 */  nop       
/* 3A82C 8005F42C 00000000 */  nop       
