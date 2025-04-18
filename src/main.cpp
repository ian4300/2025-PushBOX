#include "App.hpp"
#include "Util/Input.hpp"
#include "Core/Context.hpp"

int main(int argc, char* argv[])
{
    auto context = Core::Context::GetInstance();
    App app;

    // set icon in window.
    context->SetWindowIcon("Resources/box.png");

    while (!context->GetExit()) {
        context->Setup();

        switch (app.GetCurrentState()) {
        case App::State::START:
            app.Start();
            break;

        case App::State::UPDATE:
            app.Update();
            break;

        case App::State::END:
            app.End();
            context->SetExit(true);
            break;
        }

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        context->Update();
    }
    return 0;
}