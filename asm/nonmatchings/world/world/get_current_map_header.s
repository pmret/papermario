.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel get_current_map_header
/* 35FE8 8005ABE8 3C02800A */  lui       $v0, %hi(D_800A41E8)
/* 35FEC 8005ABEC 244241E8 */  addiu     $v0, $v0, %lo(D_800A41E8)
/* 35FF0 8005ABF0 03E00008 */  jr        $ra
/* 35FF4 8005ABF4 00000000 */   nop      
