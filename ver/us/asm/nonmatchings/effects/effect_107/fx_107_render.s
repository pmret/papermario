.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_107_render
/* 3D595C E00D693C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3D5960 E00D6940 3C02E00D */  lui       $v0, %hi(func_E00D6980)
/* 3D5964 E00D6944 24426980 */  addiu     $v0, $v0, %lo(func_E00D6980)
/* 3D5968 E00D6948 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3D596C E00D694C 2402000A */  addiu     $v0, $zero, 0xa
/* 3D5970 E00D6950 AFA20014 */  sw        $v0, 0x14($sp)
/* 3D5974 E00D6954 2402002D */  addiu     $v0, $zero, 0x2d
/* 3D5978 E00D6958 AFA40018 */  sw        $a0, 0x18($sp)
/* 3D597C E00D695C 27A40010 */  addiu     $a0, $sp, 0x10
/* 3D5980 E00D6960 AFBF0020 */  sw        $ra, 0x20($sp)
/* 3D5984 E00D6964 0C080120 */  jal       shim_queue_render_task
/* 3D5988 E00D6968 AFA20010 */   sw       $v0, 0x10($sp)
/* 3D598C E00D696C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3D5990 E00D6970 03E00008 */  jr        $ra
/* 3D5994 E00D6974 27BD0028 */   addiu    $sp, $sp, 0x28
